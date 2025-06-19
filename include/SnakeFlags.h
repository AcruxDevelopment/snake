#pragma once
#include "Flags.h"

class SnakeFlags
{
private:
    Flags m_Field1;

public:
    bool wallCollide() const;
    bool selfCollide() const;
    bool collisionBounce() const;
    bool god() const;
    bool wallCarve() const;
    bool easyWallCarve() const;
    bool shortenOnCollision() const;
    bool selfCut() const;

    void setWallCollide(bool value);
    void setSelfCollide(bool value);
    void setCollisionBounce(bool value);
    void setGod(bool value);
    void setWallCarve(bool value);
    void setEasyWallCarve(bool value);
    void setShortenOnCollision(bool value);
    void setSelfCut(bool value);

    SnakeFlags();
};