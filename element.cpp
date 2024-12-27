#include "element.h"
#include "lua.h"
#include <tinyxml2.h>
#include <iostream>

using namespace tinyxml2;
using namespace std;

bool ElementManager::loadElements() {
    XMLDocument doc;

    const std::string filePath = "./resources/elements/elements.xml";

    XMLError e = doc.LoadFile(filePath.c_str());
    if (e != XML_SUCCESS) {
        cout << "Erro ao carregar o arquivo XML: " << filePath << endl;
        return false;
    }

    XMLElement* root = doc.FirstChildElement("elements");
    if (root == nullptr) {
        cout << "Nó raiz 'elements' não encontrado!" << endl;
        return false;
    }

    for (XMLElement* element = root->FirstChildElement("element"); element != nullptr; element = element->NextSiblingElement("element")) {
        Element elem;
        const char* name = element->Attribute("name");
        const char* type = element->Attribute("type");
        const char* script = element->Attribute("script");
        if (name && type && script) {
            elem.name = name;
            elem.type = type;
            elem.script = script;
            elements.push_back(elem);
            // Lua lua;
            // string scriptPath = "./resources/elements/scripts/" + string(script) + ".lua";
            // lua.executeScript(scriptPath);
        }
    }
    return true;
}

const std::vector<Element>& ElementManager::getElements() const {
    return elements;
}
