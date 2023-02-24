#include "Engine.h"
#include <iostream>
namespace TicTacToe {

const unsigned int Engine::lineCountToWin{5};

unsigned int Engine::countEntryInDirection(int x, int y, int xOffset, int yOffset, const Point &currState) const {
    auto countInLine{0U};
    auto end{false};
    while (!end) {
        x += xOffset;
        y += yOffset;
        if (currState == map.getPointValue(x, y))
            ++countInLine;
        else
            end = true;
    }
    return countInLine;
}


GameStatus Engine::checkGameStatus(const int x, const int y, const Point &currState) const {
    auto countEntryInLine{1};
    // 8 directions checking status
    // check virtical direction
    countEntryInLine += countEntryInDirection(x, y, 0, 1, currState);
    countEntryInLine += countEntryInDirection(x, y, 0, -1, currState);
    if (countEntryInLine >= lineCountToWin) return GameStatus::Finish;
    // check main diag direction
    countEntryInLine = 1;
    countEntryInLine += countEntryInDirection(x, y, 1, 1, currState);
    countEntryInLine += countEntryInDirection(x, y, -1, -1, currState);
    if (countEntryInLine >= lineCountToWin) return GameStatus::Finish;
    // check horizontal direction
    countEntryInLine = 1;
    countEntryInLine += countEntryInDirection(x, y, 1, 0, currState);
    countEntryInLine += countEntryInDirection(x, y, -1, 0, currState);
    if (countEntryInLine >= lineCountToWin) return GameStatus::Finish;
    // check main diag direction
    countEntryInLine = 1;
    countEntryInLine += countEntryInDirection(x, y, 1, -1, currState);
    countEntryInLine += countEntryInDirection(x, y, -1, 1, currState);
    if (countEntryInLine >= lineCountToWin) return GameStatus::Finish;

    return GameStatus::Play;
}

Point Engine::updateState() {
    auto buffState{nextState};
    nextState = (nextState == Point::Cross ? Point::Zero : Point::Cross);
    return buffState;
}

int Engine::move(int x, int y) {
    if (status == GameStatus::Play) {
        auto checkNewPoint = map.getPointValue(x, y);
        if (checkNewPoint != Point::Empty) {    
            if (checkNewPoint == nextState)
                return 1; // miss click on yours
            return 2; // miss click on enemy's
        }
        auto currState{updateState()};
        if (!map.setPointValue(x, y, currState)) {
            status = checkGameStatus(x, y, currState);
            return 0;
        }
    }
    return 3;
}

}