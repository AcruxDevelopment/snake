#pragma once
#include "IDrawable.h"
#include "Point.h"
#include "SnakeFlags.h"
#include "World.h"
#include "Walls.h"
#include <vector>
#include <algorithm>

class Snake : public IDrawable
{
private:
    std::vector<Point> m_Points = {};
    SnakeFlags m_Flags = SnakeFlags();
    Point m_Direction = Point();
    shared_ptr<World> m_World = nullptr;
    uint8_t m_SafetyMoveDepth = 0;

    void popHead();
    void pushHead(Point head);
    void popTail();
    void pushTail(Point tail);

    bool isColliding(Point point) const;
    bool isSelfColliding(Point point) const;
    bool isWallColliding(Point point) const;
    void onMoveCollision(Point collisionPoint);

public:
    Point head() const;
    Point tail() const;
    Point head(size_t offset) const;
    Point tail(size_t offset) const;

    const SnakeFlags& flags() const;
    SnakeFlags& flags();

    Point direction() const;
    void setDirection(Point direction);
    void setWorld(shared_ptr<World> world);

    bool isColliding() const;
    bool isSelfColliding() const;
    bool isWallColliding() const;

    void move();
    void expand();
    void reverse();
    void die();
    void draw(Screen& screen) const;

    static void setWorld(shared_ptr<Snake> snake, shared_ptr<World> world)
    {
        snake->m_World = world;
        world->setSnake(snake);
    }

    Snake(Point point);
    Snake();
};