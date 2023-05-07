#include "Game.h"

namespace TicTacToe {

int Game::makeMove(int x, int y) {
    auto retStatus = engine_.move(x, y);
    if (!retStatus) currPlayer_ = (currPlayer_ == playerCross_ ? playerZero_ : playerCross_);
    return retStatus;
}

WinnerStatus Game::getStatus() const {
    if (engine_.getGameStatus() == GameStatus::Play) return WinnerStatus::Nobody;

    return (engine_.getCurrentState() == Point::Cross ? WinnerStatus::ZeroPlayer : WinnerStatus::CrossPlayer);
}


}