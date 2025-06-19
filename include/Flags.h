#pragma once
#include <cstdint>

class Flags
{
private:
    uint8_t m_Field;

public:
    bool get(uint8_t index) const;
    void set(uint8_t index, bool value);

    Flags();
};