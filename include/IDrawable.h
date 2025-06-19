#pragma once
#include "Screen.h"

class IDrawable
{
public:
    virtual void draw(Screen& screen) const = 0;
    virtual ~IDrawable() = default;
};