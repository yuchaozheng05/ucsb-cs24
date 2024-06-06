
#ifndef VOXMAP_H
#define VOXMAP_H

#include <map>
#include <istream>
#include <vector>
#include <queue>
#include <stack>

#include "Point.h"
#include "Route.h"

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
  Point jump(Point current, Point point) const;
  //Point jump(Point point) const;
public:
  VoxMap(std::istream& stream);
  ~VoxMap();

  Route route(Point src, Point dst);
  Route route_bfs(Point src, Point dst);
  
};

#endif