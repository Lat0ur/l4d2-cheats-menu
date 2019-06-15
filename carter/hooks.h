#pragma once

#include <memory>
#include "render.h"
#include "vmt.h"
#include "flags.h"
#include "move.h"
#include "button.h"
#include "user_cmd.h"
#include "interfaces.h"
#include "menu/menu.h"



    namespace hooks
    {
        extern void setup();

        extern std::unique_ptr<vmt> client_hook;
        extern std::unique_ptr<vmt> panel_hook;

        extern bool __fastcall create_move_hooked(void*, void*, float, user_cmd*);
        extern void __fastcall paint_traverse_hooked(void*, void*, std::uintptr_t, bool, bool);
    }
