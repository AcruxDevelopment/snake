#pragma once
#include "Point.h"
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <new>

template <typename T>
class Matrix
{
private:
    T *m_Data;
    size_t m_Width;
    size_t m_Height;
    size_t m_ItemCapacity;

    size_t to1dIndex(size_t row, size_t column) const
    {
        return (m_Width * row) + column;
    }

    void destroyData()
    {
        for (size_t i = 0; i < m_ItemCapacity; ++i)
        {
            m_Data[i].~T();
        }
        std::free(m_Data);
    }

public:
    size_t width() const { return m_Width; }
    size_t height() const { return m_Height; }

    const T &at(size_t row, size_t column) const
    {
        return m_Data[to1dIndex(row, column)];
    }

    T &at(size_t row, size_t column)
    {
        return m_Data[to1dIndex(row, column)];
    }

    const T &at(Point point) const
    {
        return m_Data[to1dIndex(point.y(), point.x())];
    }

    T &at(Point point)
    {
        return m_Data[to1dIndex(point.y(), point.x())];
    }

    void fill(const T &value)
    {
        for (size_t i = 0; i < m_ItemCapacity; ++i)
            m_Data[i] = value;
    }

    void fill(T &&value)
    {
        for (size_t i = 0; i < m_ItemCapacity; ++i)
            m_Data[i] = std::move(value);
    }

    Matrix &operator=(const Matrix &other)
    {
        if (this != &other)
        {
            destroyData();

            m_Width = other.m_Width;
            m_Height = other.m_Height;
            m_ItemCapacity = other.m_ItemCapacity;

            m_Data = static_cast<T *>(std::malloc(m_ItemCapacity * sizeof(T)));
            if (!m_Data) throw std::runtime_error("Can't allocate for Matrix.");
            for (size_t i = 0; i < m_ItemCapacity; ++i) new (&m_Data[i]) T(other.m_Data[i]);
        }
        return *this;
    }

    Matrix &operator=(Matrix &&other)
    {
        if (this != &other)
        {
            destroyData();

            m_Width = other.m_Width;
            m_Height = other.m_Height;
            m_ItemCapacity = other.m_ItemCapacity;
            m_Data = other.m_Data;

            other.m_Data = nullptr;
            other.m_Width = 0;
            other.m_Height = 0;
            other.m_ItemCapacity = 0;
        }

        return *this;
    }

    Matrix(size_t width, size_t height)
        : m_Width(width), m_Height(height), m_ItemCapacity(width * height)
    {
        m_Data = static_cast<T *>(std::malloc(m_ItemCapacity * sizeof(T)));
        if (!m_Data) throw std::runtime_error("Can't allocate for Matrix.");
        for (size_t i = 0; i < m_ItemCapacity; ++i) new (&m_Data[i]) T();
    }

    Matrix(size_t width, size_t height, const T &fillValue)
        : m_Width(width), m_Height(height), m_ItemCapacity(width * height)
    {
        m_Data = static_cast<T *>(std::malloc(m_ItemCapacity * sizeof(T)));
        if (!m_Data) throw std::runtime_error("Can't allocate for Matrix.");
        for (size_t i = 0; i < m_ItemCapacity; ++i) new (&m_Data[i]) T(fillValue);
    }

    Matrix(const Matrix &other)
        : m_Width(other.m_Width), m_Height(other.m_Height), m_ItemCapacity(other.m_ItemCapacity)
    {
        m_Data = static_cast<T *>(std::malloc(m_ItemCapacity * sizeof(T)));
        if (!m_Data) throw std::runtime_error("Can't allocate for Matrix.");
        for (size_t i = 0; i < m_ItemCapacity; ++i) new (&m_Data[i]) T(other.m_Data[i]);
    }

    Matrix(Matrix &&other)
        : m_Width(other.m_Width), m_Height(other.m_Height), m_ItemCapacity(other.m_ItemCapacity), m_Data(other.m_Data)
    {
        other.m_Data = nullptr;
        other.m_Width = 0;
        other.m_Height = 0;
        other.m_ItemCapacity = 0;
    }

    virtual ~Matrix()
    {
        if (m_Data)
            destroyData();

        m_Data = nullptr;
        m_Width = 0;
        m_Height = 0;
        m_ItemCapacity = 0;
    }
};
