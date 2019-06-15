#pragma once


    class engine
    {
    public:
        int local_player()
        {
            return tools::find_table<int(__thiscall*)(void*)>(this, 12)(this);
        }
		void get_screen_size(std::int32_t& w, std::int32_t& h)
		{
			return tools::find_table<void(__thiscall*)(void*, std::int32_t&, std::int32_t&)>(this, 5)(this, w, h);
		}
        bool in_game()
        {
            return tools::find_table<bool(__thiscall*)(void*)>(this, 26)(this);
        }

        bool connected()
        {
            return tools::find_table<bool(__thiscall*)(void*)>(this, 27)(this);
        }

        bool taking_screenshot()
        {
            return tools::find_table<bool(__thiscall*)(void*)>(this, 88)(this);
        }

        void execute_console_cmd(const char* name)
        {
            tools::find_table<void(__thiscall*)(void*, const char*)>(this, 106)(this, name);
        }
    };
