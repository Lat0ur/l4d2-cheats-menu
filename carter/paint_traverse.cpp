#include "hooks.h"


    void __fastcall hooks::paint_traverse_hooked(void* ecx, void* edx, const std::uintptr_t panel, const bool paint, const bool force) 
    {
        panel_hook->original<void(__thiscall*)(void*, std::uintptr_t, bool, bool)>(41)(ecx, panel, paint, force);

        static std::uintptr_t copy = 0;

        if (!copy && !std::strcmp(interfaces::panel_interface->find_panel_name(panel), "FocusOverlayPanel")) 
            copy = panel;

        if (panel != copy) 
            return;

        interfaces::surface_interface->text_font(9);
        interfaces::surface_interface->text_color(255, 255, 255, 255);
        interfaces::surface_interface->text_pos(20, 20);
        interfaces::surface_interface->draw_text(L"my first source engine project !", std::wcslen(L"my first source engine project !"));

		menu.draw();
    }
