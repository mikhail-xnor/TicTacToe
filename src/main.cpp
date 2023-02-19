#include "Game.h"
#include <iostream>


int main() {

    TicTacToe::Map map;
    map.setPointValue(0, 0, TicTacToe::Point::Zero);
    map.setPointValue(8, 0, TicTacToe::Point::Cross);
    map.setPointValue(0, 8, TicTacToe::Point::Zero);
    map.setPointValue(-8, 0, TicTacToe::Point::Cross);
    map.setPointValue(0, -8, TicTacToe::Point::Zero);

    for (auto i = 16; i > -17; --i) {
        for (auto j = -16; j < 17; ++j) {
            auto point{map.getPointValue(j, i)};
            std::cout << (point == TicTacToe::Point::Zero ? "0" : (point == TicTacToe::Point::Cross ? "+" : "_"));
        }
        std::cout << "\n";
    }

    return 0;
}