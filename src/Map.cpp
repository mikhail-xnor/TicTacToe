#include "Map.h"

namespace TicTacToe {

const int Map::bitMapSize{8};

Map::Map() : yLower(0), yGreater(1) { 
    map.push_back({ { 0, 1 }, { { 0, 0 } } });
}

uint64_t Map::getNewPointBitMap(int x, int y) const {
    uint64_t newPoint{1};
    auto bitMapY{ y % bitMapSize }, bitMapX{ x % bitMapSize };
    bitMapY += (bitMapY < 0 ? bitMapSize : 0);
    bitMapX += (bitMapX < 0 ? bitMapSize : 0);
    for (auto i = 1; i < bitMapSize - bitMapY; ++i)
        newPoint <<= bitMapSize;
    newPoint <<= bitMapX;
    return newPoint;
}

int Map::setPointValue(int x, int y, Point type) {
    auto Y{ y / bitMapSize - (y < 0 ? 1 : 0) };  // y in map 8*8 coords
    if (Y < yLower) {
        map.push_front({ { 0, 1 }, { { 0, 0 } } }); // expand map to down 
        --yLower;
        return setPointValue(x, y, type);
    } else if (Y >= yGreater) {
        map.push_back({ { 0, 1 }, { { 0, 0 } } }); // expand map to up 
        ++yGreater;
        return setPointValue(x, y, type);
    }
    //auto yLevelDequeSize{ abs(yGreater - yLower) }; 
    auto yLevelDequeBitMap{ std::begin(map) + Y - yLower }; // iterator on y bitMap level
    auto X{ x / bitMapSize - (x < 0 ? 1 : 0) }; // x in map 8*8 coords
    if (X < yLevelDequeBitMap->first.first) {
        yLevelDequeBitMap->second.push_front({ 0, 0 }); // expand map to left 
        --yLevelDequeBitMap->first.first;
        return setPointValue(x, y, type);
    } else if (X >= yLevelDequeBitMap->first.second) {
        yLevelDequeBitMap->second.push_back({ 0, 0 }); // expand map to right 
        ++yLevelDequeBitMap->first.second;
        return setPointValue(x, y, type);
    }
    auto bitMapPair{ std::begin(yLevelDequeBitMap->second) + X - yLevelDequeBitMap->first.first }; // iterator on x bitMap pair
    auto newPoint{ getNewPointBitMap(x, y) };
    /* MOVED TO ENGINE, BECAUSE IT'S LOGIC

    if (newPoint & bitMapPair->first && type == Point::Cross || newPoint & bitMapPair->second && type == Point::Zero)
        return 1;
    if (newPoint & bitMapPair->first & bitMapPair->second)
        return 2;

    */
    if (type == Point::Cross) {
        bitMapPair->second &= ~newPoint;
        bitMapPair->first |= newPoint;
    }
    else if (type == Point::Zero) {
        bitMapPair->first &= ~newPoint;
        bitMapPair->second |= newPoint;
    }
    else {
        bitMapPair->first &= ~newPoint;
        bitMapPair->second &= ~newPoint;
    }
    return 0;
}

Point Map::getPointValue(int x, int y) const {
    auto Y{ y / bitMapSize - (y < 0 ? 1 : 0) };  // y in map 8*8 coords
    if (Y < yLower || Y >= yGreater) {
        return Point::Empty;
    }
    auto yLevelDequeBitMap{ std::begin(map) + Y - yLower }; // iterator on y bitMap level
    auto X{ x / bitMapSize - (x < 0 ? 1 : 0) }; // x in map 8*8 coords
    if (X < yLevelDequeBitMap->first.first || X >= yLevelDequeBitMap->first.second) {
        return Point::Empty;
    }
    auto bitMapPair{ std::begin(yLevelDequeBitMap->second) + X - yLevelDequeBitMap->first.first }; // iterator on x bitMap pair
    auto newPoint{ getNewPointBitMap(x, y) };
    if (newPoint & bitMapPair->first)
        return Point::Cross;
    if (newPoint & bitMapPair->second) 
        return Point::Zero;
    return Point::Empty;
}


}