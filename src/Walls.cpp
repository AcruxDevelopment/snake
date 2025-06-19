#include "Walls.h"

void Walls::draw(Screen &screen) const
{
    Pixel pixel(Color(ColorHue::BLACK, true));
    for (size_t row = 0; row < height(); ++row)
    {
        for (size_t column = 0; column < width(); ++column)
        {
            if(at(row, column))
                screen.at(row, column) = pixel;
        }
    }
}

Walls::Walls(size_t width, size_t height, bool fillValue)
    : Matrix(width, height, fillValue) {}

Walls::Walls(size_t width, size_t height)
    : Matrix(width, height) {}