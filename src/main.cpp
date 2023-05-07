#include "Game.h"
#include <iostream>
#include <jwt-cpp/jwt.h>


int main() {

    auto token = jwt::create()
    .set_issuer("auth0")
    .set_type("JWS")
    .set_payload_claim("uuid", jwt::claim(std::string("1234")))
    .sign(jwt::algorithm::hs256{"secret"});

    

    //std::string token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXUyJ9.eyJpc3MiOiJhdXRoMCJ9.AbIJTDMFc7yUa5MhvcP03nJPyCPzZtQcGEp-zWfOkEE";
    auto decoded = jwt::decode(token);

    for(auto& e : decoded.get_payload_claims())
        std::cout << e.first << " = " << e.second << std::endl;

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