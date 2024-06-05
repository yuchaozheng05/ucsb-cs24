#include "VoxMap.h"
#include "Errors.h"
#include <bitset>
#include <queue>
#include <functional>
#include <unordered_map>
#include <sstream>

VoxMap::VoxMap(std::istream& stream) {
    if (!(stream >> width >> depth >> height)) {
        throw std::runtime_error("Failed to read map dimensions");
    }

    map.resize(height, std::vector<std::vector<bool>>(depth, std::vector<bool>(width, false)));

    std::string line;
    std::getline(stream, line); // To consume the newline character after the height value
    for (int z = 0; z < height; ++z) {
        if (!std::getline(stream, line) || !line.empty()) {
            throw std::runtime_error("Expected an empty line as tier separator");
        }

        for (int y = 0; y < depth; ++y) {
            if (!std::getline(stream, line)) {
                throw std::runtime_error("Failed to read map row");
            }

            if (line.size() < static_cast<std::string::size_type>(width / 4)) {
                std::ostringstream oss;
                oss << "Line length " << line.size() << " is less than expected " << (width / 4);
                throw std::runtime_error(oss.str());
            }

            for (int x = 0; x < width / 4; ++x) {
                char hex = line[x];
                int val = (hex >= '0' && hex <= '9') ? (hex - '0') : (hex - 'A' + 10);
                for (int bit = 0; bit < 4; ++bit) {
                    map[z][y][4 * x + bit] = (val & (8 >> bit)) != 0;
                }
            }
        }
    }
}

VoxMap::~VoxMap() {}

bool VoxMap::is_valid_point(const Point& point) const {
  return point.x >= 0 && point.x < width &&
         point.y >= 0 && point.y < depth &&
         point.z >= 0 && point.z < height;
}

bool VoxMap::is_walkable(const Point& point) const {
  return is_valid_point(point) &&
         !map[point.z][point.y][point.x] &&
         point.z > 0 && map[point.z - 1][point.y][point.x];
}

Point VoxMap::fall(Point point) const {
    while (point.z > 0 && !map[point.z - 1][point.y][point.x]) {
        point.z--;
    }
    return point;
}

Point VoxMap::jump(Point point) const {
    if (point.z + 1 < height && is_valid_point({point.x, point.y, point.z + 1}) && !map[point.z + 1][point.y][point.x]) {
        point.z++;
    }
    return point;
}

Route VoxMap::route(Point src, Point dst) {
    return route_bfs(src, dst);
}

Route VoxMap::route_bfs(Point src, Point dst) {
  if (!is_walkable(src)) throw InvalidPoint(src);
  if (!is_walkable(dst)) throw InvalidPoint(dst);

  std::queue<Point> q;
  std::map<Point, Point> came_from;
  q.push(fall(src));
  came_from[fall(src)] = src;

  while (!q.empty()) {
      Point current = q.front();
      q.pop();
      //std::cout << "Processing point: " << current << std::endl;

      if (current == dst) break;

      std::vector<Point> neighbors = {
          {current.x + 1, current.y, current.z},
          {current.x - 1, current.y, current.z},
          {current.x, current.y + 1, current.z},
          {current.x, current.y - 1, current.z}
      };

      for (Point next : neighbors) {
          if (!is_valid_point(next)) continue;

          Point next_fall = fall(next);
          if (is_walkable(next_fall) && came_from.find(next_fall) == came_from.end()) {
              //std::cout << "Adding neighbor: " << next_fall << std::endl;
              q.push(next_fall);
              came_from[next_fall] = current;
          }

          Point next_jump = jump(next);
          if (is_walkable(next_jump) && came_from.find(next_jump) == came_from.end()) {
              //std::cout << "Adding jumpable neighbor: " << next_jump << std::endl;
              q.push(next_jump);
              came_from[next_jump] = current;
          }
      }
  }

  if (came_from.find(dst) == came_from.end()) {
      //std::cout << "No route found from " << src << " to " << dst << std::endl;
      throw NoRoute(src, dst);
  }

  Route route;
  for (Point at = dst; at != src; at = came_from[at]) {
      Point prev = came_from[at];
      if (at.x == prev.x + 1) route.push_back(Move::EAST);
      else if (at.x == prev.x - 1) route.push_back(Move::WEST);
      else if (at.y == prev.y + 1) route.push_back(Move::SOUTH);
      else if (at.y == prev.y - 1) route.push_back(Move::NORTH);
  }
  std::reverse(route.begin(), route.end());
  //std::cout << "Route found: " << route << std::endl;
  return route;
}
