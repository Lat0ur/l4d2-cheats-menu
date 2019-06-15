#include "interfaces.h"


    client* interfaces::client_interface = nullptr;
    engine* interfaces::engine_interface = nullptr;
    panel* interfaces::panel_interface = nullptr;
    surface* interfaces::surface_interface = nullptr;
    client_entity* interfaces::client_entity_interface = nullptr;
	i_inputsytem* InputSystem = nullptr;

    void interfaces::setup()
    {
        client_interface = tools::find_interface<client*>("client.dll", "VClient016");
        engine_interface = tools::find_interface<engine*>("engine.dll", "VEngineClient013");
        panel_interface = tools::find_interface<panel*>("vgui2.dll", "VGUI_Panel009");
        surface_interface = tools::find_interface<surface*>("vguimatsurface.dll", "VGUI_Surface031");
        client_entity_interface = tools::find_interface<client_entity*>("client.dll", "VClientEntityList003");
		InputSystem             = tools::find_interface<i_inputsytem*>("inputsystem.dll", "InputSystemVersion");


    }
