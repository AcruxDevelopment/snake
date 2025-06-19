#pragma once
#include <iostream>
#include "Matrix.h"
#include "Pixel.h"

class Screen : public Matrix<Pixel>
{
public:
    void draw();

    Screen(size_t width, size_t height);
    Screen(size_t width, size_t height, Pixel pixel);
};
