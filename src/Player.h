#include <string>

namespace TicTacToe {

class Player {
    std::string uuid_;

public:
    Player(std::string uuid);

    std::string getUuid() const { return uuid_; };
};

}