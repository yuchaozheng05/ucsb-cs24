
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <functional>
//struct Point {
//  int x;
//  int y;
//  int z;
//
//  Point() {}
//  Point(int x, int y, int z): x(x), y(y), z(z) {}
//};
//
//inline bool operator==(const Point& lhs, const Point& rhs) {
//    return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
//}
//
//inline bool operator!=(const Point& lhs, const Point& rhs) {
//    return !(lhs == rhs);
//}
//
//inline bool operator<(const Point& lhs, const Point& rhs) {
//    if (lhs.z != rhs.z) return lhs.z < rhs.z;
//    if (lhs.y != rhs.y) return lhs.y < rhs.y;
//    return lhs.x < rhs.x;
//}
//
//std::istream& operator >> (std::istream& stream, Point& point);
//std::ostream& operator << (std::ostream& stream, const Point& point);
struct Point {
    int x, y, z;

    Point() {}
    Point(int x, int y, int z): x(x), y(y), z(z) {}

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }
};

namespace std {
template <>
struct hash<Point> {
    size_t operator()(const Point& point) const {
        // Effective hash combination formula
        return ((std::hash<int>()(point.x) ^ (std::hash<int>()(point.y) << 1)) >> 1) ^ (std::hash<int>()(point.z) << 1);
    }
};
}

std::istream& operator>>(std::istream& stream, Point& point);
std::ostream& operator<<(std::ostream& stream, const Point& point);

#endif



//#endif