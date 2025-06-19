#pragma once
#include "AnsiColor.h"
typedef unsigned char underlhue_t;

enum ColorHue : underlhue_t
{
    BLACK        = 0,
    RED          = 1,
    GREEN        = 2,
    YELLOW       = 3,
    BLUE         = 4,
    MAGENTA      = 5,
    CYAN         = 6,
    WHITE        = 7,
};

class Color
{
private:
    // xxxxxxxy
    // x -> hue
    // y -> bright flag
    underlhue_t m_Data;

public:

    ColorHue getHue() const;
    void setHue(ColorHue hue);
    bool isBright() const;
    void setBright(bool bright);

    AnsiColor toAnsiBackground();
    AnsiColor toAnsiForeground();

    Color(ColorHue hue, bool bright);
    Color();
};