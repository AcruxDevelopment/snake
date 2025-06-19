#include "Point.h"

dimension_t Point::x() const { return m_X; }

dimension_t Point::y() const { return m_Y; }

bool Point::in(const std::vector<Point> &vector) const
{
    return in(vector.data(), vector.size());
}

bool Point::in(const Point *array, size_t size) const
{
    for (size_t i = 0; i < size; ++i)
    {
        Point point = array[i];
        if (*this == point)
            return true;
    }
    return false;
}

Point Point::operator+(Point other) const
{
    return Point(m_X + other.m_X, m_Y + other.m_Y);
}

Point Point::operator-(Point other) const
{
    return Point(m_X - other.m_X, m_Y - other.m_Y);
}

Point Point::operator*(Point other) const
{
    return Point(m_X * other.m_X, m_Y * other.m_Y);
}

Point Point::operator/(Point other) const
{
    return Point(m_X / other.m_X, m_Y / other.m_Y);
}

Point Point::operator-() const
{
    return Point(-m_X, -m_Y);
}

bool Point::operator==(Point other) const
{
    return m_X == other.m_X && m_Y == other.m_Y;
}

bool Point::operator!=(Point other) const
{
    return !(*this == other);
}

Point::Point(dimension_t x, dimension_t y)
    : m_X(x), m_Y(y) {}

Point::Point(dimension_t dimensions)
    : m_X(dimensions), m_Y(dimensions) {}

Point::Point()
    : m_X(0), m_Y(0) {}