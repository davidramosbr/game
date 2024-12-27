#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

struct Player {
    uint id;
    std::string name;
    uint level;
    uint position;
};

class PlayerManager {
public:
    bool loadPlayer(std::string);
    bool savePlayer(uint);
    const std::vector<Player>& getPlayers() const;

private:
    std::vector<Player> players;
};

#endif
