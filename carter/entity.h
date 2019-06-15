#pragma once


    class entity 
    {
    public:
        int health() 
        {
            return *reinterpret_cast<int*>(this + 0xEC);
        }

        int team_num() 
        {
            return *reinterpret_cast<int*>(this + 0xE4);
        }

        int flags() 
        {
            return *reinterpret_cast<int*>(this + 0xF0);
        }
    };
