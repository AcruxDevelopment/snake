#include "AnsiColor.h"

std::ostream& ansi(std::ostream& os, AnsiColor color)
{
    return os << "\033[" << static_cast<int>(color) << "m";
}