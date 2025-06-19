#include "Screen.h"

void Screen::draw()
{
    for (size_t row = 0; row < height(); ++row)
    {
        for (size_t column = 0; column < width(); ++column)
        {
            std::cout << at(row, column);
        }
        ansi(std::cout, AnsiColor::RESET);
        std::cout << '\n';
    }
}

Screen::Screen(size_t width, size_t height) : Matrix(width, height) {}
Screen::Screen(size_t width, size_t height, Pixel pixel) : Matrix(width, height, pixel) {}