#include "hooks.h"


    bool __fastcall hooks::create_move_hooked(void* ecx, void* edx, const float frame, user_cmd* cmd)
    {
        client_hook->original<bool(__thiscall*)(void*, float, user_cmd*)>(27)(ecx, frame, cmd);

        auto entity = interfaces::client_entity_interface->find_entity(interfaces::engine_interface->local_player());

        if (!cmd || !cmd->command_number)
            return true;

        cmd->buttons |= button_bull_rush;

        if (cmd->buttons & button_jump && !(entity->flags() & flags_on_ground))
            cmd->buttons &= ~button_jump;

        return false;
    }
