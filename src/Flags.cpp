#include "Flags.h"

bool Flags::get(uint8_t index) const
{
    if (index >= sizeof(uint8_t)*8) return false; // Out of bounds
    return (m_Field >> index) & 1;
}

void Flags::set(uint8_t index, bool value)
{
    if (index >= sizeof(uint8_t)*8) return; // Out of bounds

    if (value)
        m_Field |= (1U << index);  // Set bit
    else
        m_Field &= ~(1U << index); // Clear bit
}

Flags::Flags() : m_Field(0) {}