#include <deque>
#include <math.h>

namespace TicTacToe {

enum class Point { Empty, Cross, Zero };

// TODO: class Pos(x, y) ??? 

class Map {
    std::deque<std::pair<std::pair<int, int>, std::deque<std::pair<uint64_t, uint64_t>>>> map; 
    /* 
    bitMap = 8*8
    map[y].first.first == xLower; 
    map[y].first.second == xGreater; 
    map[y].second[x].first == crossesBitMap; 
    map[y].second[x].second == zerosBitMap;
    */
    int yLower, yGreater;
    static const int bitMapSize;

    uint64_t getNewPointBitMap(int x, int y) const;
public:
    Map();

    Point getPointValue(int x, int y) const;

    int setPointValue(int x, int y, Point type);

    // TODO: getDiagonalsStatus method by using bitMaps

};

}