#include "World.h"

shared_ptr<Screen> World::screen() const { return m_Screen; }
shared_ptr<Walls> World::walls() const { return m_Walls; }
shared_ptr<Snake> World::snake() const { return m_Snake; }
bool World::isGameOver() const { return m_IsGameOver; }

void World::setScreen(shared_ptr<Screen> screen) { m_Screen = screen; }
void World::setWalls(shared_ptr<Walls> walls) { m_Walls = walls; }
void World::setSnake(shared_ptr<Snake> snake) { m_Snake = snake; }
void World::setGameOver() { m_IsGameOver = true; }

World::World()
    : m_Screen(nullptr), m_Snake(nullptr) {}