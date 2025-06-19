#pragma once
#include <memory>
using std::shared_ptr;

class Screen;
class Walls;
class Snake;

class World
{
private:
    shared_ptr<Screen> m_Screen;
    shared_ptr<Walls> m_Walls;
    shared_ptr<Snake> m_Snake;
    bool m_IsGameOver;

public:
    shared_ptr<Screen> screen() const;
    shared_ptr<Walls> walls() const;
    shared_ptr<Snake> snake() const;
    bool isGameOver() const;

    void setScreen(shared_ptr<Screen> screen);
    void setWalls(shared_ptr<Walls> walls);
    void setSnake(shared_ptr<Snake> snake);
    void setGameOver();

    World();
};