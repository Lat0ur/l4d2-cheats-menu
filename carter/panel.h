#pragma once
#include "tools.h"


    class panel
    {
    public:
        const char* find_panel_name(const unsigned int name)
        {
            return tools::find_table<const char*(__thiscall*)(void*, unsigned int)>(this, 36)(this, name);
        }

        const char* find_class_name(const unsigned int name)
        {
            return tools::find_table<const char*(__thiscall*)(void*, unsigned int)>(this, 37)(this, name);
        }
    };
