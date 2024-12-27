#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

struct Position {
    uint posX;
    uint posY;
    uint posZ;
    uint posM;
};

class Map {
public:
    bool loadMap();
    const std::vector<Position>& getMap() const;

private:
    std::vector<Position> mapPositions;
};

#endif
