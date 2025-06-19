#include "Color.h"

ColorHue Color::getHue() const
{
    return (ColorHue)(m_Data >> 1);
}

void Color::setHue(ColorHue hue)
{
    m_Data = (hue << 1) | (m_Data & 0x01);
}

bool Color::isBright() const
{
    return m_Data & 0x01;
}

void Color::setBright(bool bright)
{
    if (bright)
        m_Data |= 0x01;
    else
        m_Data &= ~0x01;
}

AnsiColor Color::toAnsiBackground()
{
    int ansiBase = isBright() ? BG_BRIGHT_BLACK : BG_BLACK;
    return (AnsiColor)(ansiBase + getHue());
}

AnsiColor Color::toAnsiForeground()
{
    int ansiBase = isBright() ? FG_BLACK : FG_BRIGHT_BLACK;
    return (AnsiColor)(ansiBase + getHue());
}

Color::Color(ColorHue hue, bool bright)
{
    setHue(hue);
    setBright(bright);
}

Color::Color()
{
    setHue(ColorHue::BLACK);
    setBright(false);
}