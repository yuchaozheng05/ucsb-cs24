
#ifndef POINT_H
#define POINT_H

#include <iostream>

struct Point {
  int x;
  int y;
  int z;

  Point() {}
  Point(int x, int y, int z): x(x), y(y), z(z) {}
};

inline bool operator==(const Point& lhs, const Point& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

inline bool operator!=(const Point& lhs, const Point& rhs) {
    return !(lhs == rhs);
}

inline bool operator<(const Point& lhs, const Point& rhs) {
    if (lhs.z != rhs.z) return lhs.z < rhs.z;
    if (lhs.y != rhs.y) return lhs.y < rhs.y;
    return lhs.x < rhs.x;
}
namespace std {
    template<> struct hash<Point> {
        size_t operator()(const Point& point) const {
            size_t h1 = std::hash<int>{}(point.x);
            size_t h2 = std::hash<int>{}(point.y);
            size_t h3 = std::hash<int>{}(point.z);
            // Combine hashes
            return h1 ^ (h2 << 1) ^ (h3 << 2); // Shift and XOR for simple combination
        }
    };
}
std::istream& operator >> (std::istream& stream, Point& point);
std::ostream& operator << (std::ostream& stream, const Point& point);




#endif