#include "lua.h"
#include <iostream>

using namespace std;

Lua::Lua() {
    L = luaL_newstate();
    if (L == nullptr) {
        cout << "Erro ao criar o estado Lua." << endl;
    }
    luaL_openlibs(L);
}

Lua::~Lua() {
    if (L != nullptr) {
        lua_close(L);
    }
}

bool Lua::executeScript(const std::string& scriptName) {
    if (luaL_dofile(L, scriptName.c_str()) != LUA_OK) {
        cout << "Erro ao executar o script Lua: " << scriptName << endl;
        cout << lua_tostring(L, -1) << endl;
        return false;
    }

    return true;
}
