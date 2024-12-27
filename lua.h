#ifndef LUA_H
#define LUA_H

#include <string>
#include <lua.hpp>

class Lua {
public:
    Lua();
    ~Lua();
    bool executeScript(const std::string& scriptName);

private:
    lua_State* L;
};

#endif
