#include "Screen.h"
#include "Walls.h"
#include "Snake.h"
#include "Terminal.h"
#include <thread>
#include <chrono>
#include <map>
#include <csignal>

#define GAME_SLEEP_TIME 100
#define WINDOW_H 30
#define WINDOW_W 50

const Point UP(0, -1);
const Point DOWN(0, 1);
const Point LEFT(-1, 0);
const Point RIGHT(1, 0);

std::map<char, Point> keycodeMovements =
{
    {'w', UP},
    {'s', DOWN},
    {'a', LEFT},
    {'d', RIGHT}
};

char control;
void inputLoop(shared_ptr<World> world)
{
    auto snake = world->snake();
    while(!world->isGameOver())
    {
        control = getChar();
    }
}

void gameLoop(shared_ptr<World> world)
{
    Pixel pixel(Color(ColorHue::BLACK, false));
    auto sleepTime = std::chrono::milliseconds(GAME_SLEEP_TIME);
    auto screen = world->screen();
    auto walls = world->walls();
    auto snake = world->snake();

    unsigned long long i = 0;
    while(!world->isGameOver())
    {
        setCursor(0, 0);
        screen->fill(pixel);
        snake->draw(*screen);
        walls->draw(*screen);
        screen->draw();

        std::this_thread::sleep_for(sleepTime);
        if(control != ' ')
        {
            snake->setDirection(keycodeMovements[control]);
            control = ' ';
        }
        snake->move();
        if(i < 30) snake->expand();

        std::cout << '\n';
        ++i;
    }
}

std::thread gameLoopThread;
std::thread inputLoopThread;

void sigHandler(int sig)
{
    disableRawMode();
    std::cout << "GOT SIGNAL " << sig << '\n';
    exit(0);
}

void setupSigHandlers()
{
    signal(SIGINT, sigHandler);
    signal(SIGTSTP, sigHandler);
    signal(SIGSEGV, sigHandler);
}

int main()
{
    setupSigHandlers();
    enableRawMode();
    shared_ptr<World> world = std::make_shared<World>();
    shared_ptr<Screen> screen = std::make_shared<Screen>(WINDOW_W, WINDOW_H);
    shared_ptr<Walls> walls = std::make_shared<Walls>(Walls::fromFile("/home/alenika/Desktop/dev/snake/build/walls.txt"));
    shared_ptr<Snake> snake = std::make_shared<Snake>(Point(WINDOW_W/2, WINDOW_H/2));

    world->setScreen(screen);
    world->setWalls(walls);
    Snake::setWorld(snake, world);
    snake->setDirection(Point(0, -1));

    snake->flags().setWallCarve(true);
    //snake->flags().setEasyWallCarve(true);
    //snake->flags().setGod(true);
    //snake->flags().setShortenOnCollision(true);
    //snake->flags().setCollisionBounce(true);
    snake->flags().setSelfCut(true);

    gameLoopThread = std::thread(gameLoop, world);
    inputLoopThread = std::thread(inputLoop, world);
    gameLoopThread.join();
    inputLoopThread.join();

    disableRawMode();
    return 0;
}