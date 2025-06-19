#include "SnakeFlags.h"

bool SnakeFlags::wallCollide() const { return m_Field1.get(0); }
bool SnakeFlags::selfCollide() const { return m_Field1.get(1); }
bool SnakeFlags::collisionBounce() const { return m_Field1.get(2); }
bool SnakeFlags::god() const { return m_Field1.get(3); }
bool SnakeFlags::wallCarve() const { return m_Field1.get(4); }
bool SnakeFlags::easyWallCarve() const { return m_Field1.get(5); }
bool SnakeFlags::shortenOnCollision() const { return m_Field1.get(6); }
bool SnakeFlags::selfCut() const { return m_Field1.get(7); }

void SnakeFlags::setWallCollide(bool value) { return m_Field1.set(0, value); }
void SnakeFlags::setSelfCollide(bool value) { return m_Field1.set(1, value); }
void SnakeFlags::setCollisionBounce(bool value) { return m_Field1.set(2, value); }
void SnakeFlags::setGod(bool value) { return m_Field1.set(3, value); }
void SnakeFlags::setWallCarve(bool value) { return m_Field1.set(4, value); }
void SnakeFlags::setEasyWallCarve(bool value) { return m_Field1.set(5, value); }
void SnakeFlags::setShortenOnCollision(bool value) { return m_Field1.set(6, value); }
void SnakeFlags::setSelfCut(bool value) { return m_Field1.set(7, value); }

SnakeFlags::SnakeFlags() : m_Field1(Flags())
{
    setWallCollide(true);
    setSelfCollide(true);
    setCollisionBounce(false);
    setGod(false);
    setWallCarve(false);
    setEasyWallCarve(false);
    setShortenOnCollision(false);
    setSelfCut(false);
}