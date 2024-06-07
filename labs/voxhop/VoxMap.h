#ifndef VOXMAP_H
#define VOXMAP_H

#include <map>
#include <istream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include "Point.h"
#include "Route.h"
#include <functional>

struct PointHash {
    size_t operator()(const Point& p) const {
        size_t hash = 1331; // A large prime number as base
        hash = hash * 31 + std::hash<int>()(p.x); // 31 is a small prime number
        hash = hash * 31 + std::hash<int>()(p.y);
        hash = hash * 31 + std::hash<int>()(p.z);
        return hash;
    }
};
class VoxMap {
  // Member Variables
  int width;
  int depth;
  int height;
  
  std::vector<std::vector<std::vector<bool>>> map;

  // Helper Functions
  bool is_valid_point(const Point& point) const;
  bool is_walkable(const Point& point) const;
  Point fall(Point point) const;
  Point jump(Point point) const;
  bool can_move_to(const Point& current, const Point& next);
  //Move determine_move(const Point& from, const Point& to) const;
  //bool can_move_horizontally(const Point& current, const Point& next);
  std::unordered_map<Point, Point, PointHash, std::equal_to<Point>> came_from;
public:
  VoxMap(std::istream& stream);
  ~VoxMap();

  Route route(Point src, Point dst);
  Route route_bfs(Point src, Point dst);
};

#endif