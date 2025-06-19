#pragma once
#include "Color.h"

class Pixel
{
private:
    Color m_Color;

public:
    Color color() const;

    Pixel(Color color);
    Pixel();
};

std::ostream& operator<<(std::ostream& os, const Pixel& pixel);