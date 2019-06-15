#include "hooks.h"


    std::unique_ptr<vmt> hooks::client_hook = nullptr;
    std::unique_ptr<vmt> hooks::panel_hook = nullptr;

    void hooks::setup()
    {
        const auto client_mode_pointer = reinterpret_cast<void*(__cdecl*)()>(reinterpret_cast<std::uintptr_t>(
            GetModuleHandleA("client.dll")) + 0x223670);

        client_hook = std::make_unique<vmt>(client_mode_pointer());
        panel_hook = std::make_unique<vmt>(interfaces::panel_interface);

        client_hook->hook(reinterpret_cast<void*>(create_move_hooked), 27);
        panel_hook->hook(reinterpret_cast<void*>(paint_traverse_hooked), 41);
    }


/*TODO:
aimbot
esp
classid
nospread
fsnhook
a menu
*/
