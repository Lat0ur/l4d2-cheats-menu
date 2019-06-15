#pragma once

#include "tools.h"
#include "entity.h"


    class client_entity
    {
    public:
        entity* find_entity(const int index)
        {
            return tools::find_table<entity*(__thiscall*)(void*, int)>(this, 3)(this, index);
        }
    };
