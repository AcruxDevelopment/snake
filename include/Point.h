#pragma once
#include <cstddef>
#include <vector>
typedef size_t dimension_t;

class Point
{
private:
    dimension_t m_X;
    dimension_t m_Y;

public:
    dimension_t x() const;
    dimension_t y() const;

    bool in(const std::vector<Point> &vector) const;
    bool in(const Point *array, size_t size) const;

    Point operator+(Point other) const;
    Point operator-(Point other) const;
    Point operator*(Point other) const;
    Point operator/(Point other) const;
    Point operator-() const;

    bool operator==(Point other) const;
    bool operator!=(Point other) const;

    Point(dimension_t x, dimension_t y);
    Point(dimension_t dimensions);
    Point();
};