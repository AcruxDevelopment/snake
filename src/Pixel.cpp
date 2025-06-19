#include "Pixel.h"

Color Pixel::color() const { return m_Color; }

Pixel::Pixel(Color color) : m_Color(color) {}
Pixel::Pixel() : m_Color(Color()) {}

std::ostream& operator<<(std::ostream& os, const Pixel& pixel)
{
    ansi(os, pixel.color().toAnsiForeground());
    ansi(os, pixel.color().toAnsiBackground());
    std::cout << "  ";
    return os;
}
