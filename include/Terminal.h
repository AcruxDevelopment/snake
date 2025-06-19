#pragma once
#include <iostream>
#include <termios.h>
#include <unistd.h>

static termios origTermios;

static void enableRawMode()
{
    tcgetattr(STDIN_FILENO, &origTermios);        // Save original terminal state
    termios raw = origTermios;
    raw.c_lflag &= ~(ICANON | ECHO);              // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);       // Apply changes immediately
}

static void disableRawMode()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &origTermios);  // Restore original settings
}

static char getChar()
{
    char ch;
    read(STDIN_FILENO, &ch, 1);  // Read 1 character
    return ch;
}

static void setCursor(unsigned int row, unsigned int column)
{
    std::cout << "\033[" << row << ";" << column << "H";
}