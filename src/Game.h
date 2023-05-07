#include "Engine.h"
#include "Player.h"

namespace TicTacToe {

enum class WinnerStatus { Nobody, CrossPlayer, ZeroPlayer };

class Game {
    Player *playerCross_, *playerZero_, *currPlayer_;
    Engine engine_;
public:
    Game(Player *playerCross, Player *playerZero) : playerCross_(playerCross), playerZero_(playerZero), currPlayer_(playerCross) {};

    WinnerStatus getStatus() const;

    Point getPointValue(int x, int y) const { return engine_.getPointValue(x, y); }

    int makeMove(int x, int y);

    Player* getCurrentPlayer() { return currPlayer_; };

    std::pair<Player*, Player*> getPlayers() { return { playerCross_, playerZero_ }; };

    // TODO: moves history???

    //int resotore();

    //int createSnapshot() const;
};

}

// game with 2 players*

// player->waitMove();

// then players switch ???

