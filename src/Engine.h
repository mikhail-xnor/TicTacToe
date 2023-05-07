#include "Map.h"

namespace TicTacToe {

enum class GameStatus { Play, Finish };

/* TODO: remove
class EngineSnapshot
{
    Map map;
    Point nextState;
    GameStatus status;
public:
    EngineSnapshot(Map _map, Point _nextState, GameStatus _status) : map(_map), nextState(_nextState), status(_status) {}
    auto getMap() const { return map; }
    auto getNextState() const { return nextState; }
    auto getStatus() const { return status; }
};
*/

class Engine {
    Map map;
    Point nextState;
    GameStatus status;
    static const unsigned int lineCountToWin;

    unsigned int countEntryInDirection(int x, int y, int xOffset, int yOffset, const Point &currState) const;

    GameStatus checkGameStatus(const int x, const int y, const Point &currState) const;

    Point updateState();
public:
    Engine() : nextState(Point::Cross), status(GameStatus::Play) {}

    int move(int x, int y);

    GameStatus getGameStatus() const { return status; }

    Point getCurrentState() const { return nextState; }

    Point getPointValue(int x, int y) const { return map.getPointValue(x, y); }
};

}