#pragma once
#include <iostream>

enum AnsiColor
{
    // Foreground colors
    FG_BLACK        = 30,
    FG_RED          = 31,
    FG_GREEN        = 32,
    FG_YELLOW       = 33,
    FG_BLUE         = 34,
    FG_MAGENTA      = 35,
    FG_CYAN         = 36,
    FG_WHITE        = 37,

    // Bright foreground colors
    FG_BRIGHT_BLACK   = 90,
    FG_BRIGHT_RED     = 91,
    FG_BRIGHT_GREEN   = 92,
    FG_BRIGHT_YELLOW  = 93,
    FG_BRIGHT_BLUE    = 94,
    FG_BRIGHT_MAGENTA = 95,
    FG_BRIGHT_CYAN    = 96,
    FG_BRIGHT_WHITE   = 97,

    // Background colors
    BG_BLACK        = 40,
    BG_RED          = 41,
    BG_GREEN        = 42,
    BG_YELLOW       = 43,
    BG_BLUE         = 44,
    BG_MAGENTA      = 45,
    BG_CYAN         = 46,
    BG_WHITE        = 47,

    // Bright background colors
    BG_BRIGHT_BLACK   = 100,
    BG_BRIGHT_RED     = 101,
    BG_BRIGHT_GREEN   = 102,
    BG_BRIGHT_YELLOW  = 103,
    BG_BRIGHT_BLUE    = 104,
    BG_BRIGHT_MAGENTA = 105,
    BG_BRIGHT_CYAN    = 106,
    BG_BRIGHT_WHITE   = 107,

    RESET	      = 0
};

std::ostream& ansi(std::ostream& os, AnsiColor color);