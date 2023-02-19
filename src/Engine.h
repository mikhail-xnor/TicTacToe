#include "Map.h"
#include "Player.h"

namespace TicTacToe {

class EngineSnapshot
{
    Map map;
    Point nextState;
public:
    EngineSnapshot(Map _map, Point _nextState) : map(_map), nextState(_nextState) {}
    auto getMap() const { return map; }
    auto getNextState() const { return nextState; }
};

class Engine {
    Map map;
    Point nextState;
public:
    Engine() : nextState(Point::Cross) {}

    int move(int x, int y);

    //int resotore();

    //int createSnapshot() const;
};

}