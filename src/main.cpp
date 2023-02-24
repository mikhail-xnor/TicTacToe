#include "Game.h"
#include <iostream>


int main() {

    TicTacToe::Engine engine;

    for (auto i = 0; i != 5; ++i) {
        engine.move(0, -i);
        engine.move(4 - i, 0);
    }

    //engine.getCurrentState() TicTacToe::Point::Zero;
    //engine.getGameStatus() TicTacToe::GameStatus::Finish;

    for (auto i = 16; i > -17; --i) {
        for (auto j = -16; j < 17; ++j) {
            auto point{engine.getPointValue(j, i)};
            std::cout << (point == TicTacToe::Point::Zero ? "0" : (point == TicTacToe::Point::Cross ? "+" : "_"));
        }
        std::cout << "\n";
    }

    return 0;
}