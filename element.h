#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>
#include <vector>

struct Element {
    std::string name;
    std::string type;
    std::string script;
};

class ElementManager {
public:
    bool loadElements();
    const std::vector<Element>& getElements() const;

private:
    std::vector<Element> elements;
};

#endif
