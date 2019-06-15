#pragma once


    class client
    {
    public:
        void* find_all_classes()
        {
            return tools::find_table<void*(__thiscall*)(void*)>(this, 7)(this);
        }
    };
