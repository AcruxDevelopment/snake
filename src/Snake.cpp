#include "Snake.h"

void Snake::popHead()
{
    m_Points.erase(m_Points.begin());
}

void Snake::pushHead(Point head)
{
    m_Points.insert(m_Points.begin(), head);
}

void Snake::popTail()
{
    m_Points.erase(m_Points.end()-1);
}

void Snake::pushTail(Point tail)
{
    m_Points.push_back(tail);
}

bool Snake::isColliding(Point point) const
{
    return isSelfColliding(point) || isWallColliding(point);
}

bool Snake::isSelfColliding(Point point) const
{
    if(!m_Flags.selfCollide()) return false;
    return point.in(m_Points.data()+1, m_Points.size()-1);
}

bool Snake::isWallColliding(Point point) const
{
    if(!m_Flags.wallCollide()) return false;

    auto walls = m_World->walls();
    if(point.x() >= walls->width() || point.y() >= walls->height()) return false;

    return m_World->walls()->at(point.y(), point.x());
}

Point Snake::head() const
{
    return m_Points[0];
}

Point Snake::tail() const
{
    return *(m_Points.end()-1);
}

Point Snake::head(size_t offset) const
{
    return m_Points[offset];
}

Point Snake::tail(size_t offset) const
{
    return *(m_Points.end()-1-offset);
}

const SnakeFlags& Snake::flags() const
{
    return m_Flags;
}

SnakeFlags& Snake::flags()
{
    return m_Flags;
}

Point Snake::direction() const
{
    return m_Direction;
}

void Snake::setDirection(Point direction)
{
    m_Direction = direction;
}

bool Snake::isColliding() const
{
    return isColliding(head());
}

bool Snake::isSelfColliding() const
{
    return isSelfColliding(head());
}

// TODO
bool Snake::isWallColliding() const
{
    return isWallColliding(head());
}

void Snake::move()
{
    Point newHead = head() + m_Direction;
    pushHead(newHead);

    if(isColliding())
    {
        popHead();
        onMoveCollision(newHead);
    }
    else
    {
        popTail();
    }
}

void Snake::onMoveCollision(Point collisionPoint)
{
    bool collisionBounceHandled = false;
    bool wallCarveHandled = false;
    bool selfCutHandled = false;
    bool shortenOnCollisionHandled = false;
    bool dieHandled = false;

    if(m_Flags.collisionBounce())
    {
        reverse();
        if(m_SafetyMoveDepth < 1)
        {
            ++m_SafetyMoveDepth;
            move();
        }
        collisionBounceHandled = true;
    }

    if(m_Flags.wallCarve() && m_World->walls()->at(collisionPoint))
    {
        m_World->walls()->at(collisionPoint) = false;
        if(m_Flags.easyWallCarve() && m_SafetyMoveDepth < 1)
        {
            ++m_SafetyMoveDepth;
            move();
        }
        wallCarveHandled = true;
    }

    if(m_Flags.selfCut())
    {
        auto pointIndex = std::find(m_Points.begin()+1, m_Points.end(), collisionPoint);
        if(pointIndex != m_Points.end())
        {
            Point additionTail;
            while(pointIndex != m_Points.end())
            {
                additionTail = tail(1);
                popTail();
            }
            if(m_SafetyMoveDepth < 1)
            {
                ++m_SafetyMoveDepth;
                move();
                pushTail(additionTail);
            }
            selfCutHandled = true;
        }
    }

    if(m_Flags.shortenOnCollision() && m_Points.size() > 1 && !selfCutHandled)
    {
        popTail();
        shortenOnCollisionHandled = true;
    }

    if(!m_Flags.god() && !wallCarveHandled && !collisionBounceHandled && !shortenOnCollisionHandled && !selfCutHandled)
    {
        die();
        dieHandled = true;
    }
    m_SafetyMoveDepth = 0;
}

void Snake::expand()
{
    Point expandDirection = (m_Points.size() == 1) ? -m_Direction : tail() - tail(1);
    pushTail(tail() + expandDirection);
}

void Snake::reverse()
{
    std::reverse(m_Points.begin(), m_Points.end());
    m_Direction = head() - head(1);
}

void Snake::die()
{
    m_World->setGameOver();
    m_Direction = Point();
}

void Snake::draw(Screen& screen) const
{
    Pixel headPixel(Color(ColorHue::YELLOW, false));
    Pixel darkPixel(Color(ColorHue::GREEN, false));
    Pixel brightPixel(Color(ColorHue::GREEN, true));

    size_t i = 0;
    for(const auto& point : m_Points)
    {
        screen.at(point.y(), point.x()) = 
            (i == 0) ? headPixel :
            (i % 2 == 0) ? brightPixel :
            darkPixel;
        ++i;
    }
}

Snake::Snake(Point point)
{
    pushHead(point);
}

Snake::Snake()
{
    pushHead(Point());
}