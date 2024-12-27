#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <vector>

struct Monster {
    std::string name;
    std::string type;
    std::string script;
};

class MonsterManager {
public:
    bool loadMonsters();
    const std::vector<Monster>& getMonsters() const;

private:
    std::vector<Monster> monsters;
};

#endif
