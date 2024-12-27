#include "monster.h"
#include "lua.h"
#include <tinyxml2.h>
#include <iostream>

using namespace tinyxml2;
using namespace std;

bool MonsterManager::loadMonsters() {
    XMLDocument doc;

    const std::string filePath = "./resources/monsters/monsters.xml";

    XMLError e = doc.LoadFile(filePath.c_str());
    if (e != XML_SUCCESS) {
        cout << "Erro ao carregar o arquivo XML: " << filePath << endl;
        return false;
    }

    XMLElement* root = doc.FirstChildElement("monsters");
    if (root == nullptr) {
        cout << "Nó raiz 'monsters' não encontrado!" << endl;
        return false;
    }

    for (XMLElement* monster = root->FirstChildElement("monster"); monster != nullptr; monster = monster->NextSiblingMonster("monster")) {
        Monster monsterElem;
        const char* name = monster->Attribute("name");
        const char* race = monster->Attribute("race");
        if (name && race) {
            monsterElem.name = name;
            monsterElem.race = type;
            /*
                Aqui eu vou buscar por um xml em: 
                ./resources/monsters/ + string(race) + "/" + string(name) + ".xml"
                e nesse xml vão ser os dados gerais do monstro que vou buscar e colocar
                aqui no monsterElem.
            */
            monsters.push_back(monsterElem);
        }
    }
    return true;
}

const std::vector<Monster>& MonsterManager::getMonsters() const {
    return monsters;
}
