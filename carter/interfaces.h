#pragma once

#include "tools.h"
#include "client.h"
#include "engine.h"
#include "panel.h"
#include "surface.h"
#include "client_entity.h"
#include "i_input_system.h"


    namespace interfaces
    {
        extern void setup();

        extern client* client_interface;
        extern engine* engine_interface;
        extern panel* panel_interface;
        extern surface* surface_interface;
       extern client_entity* client_entity_interface;
	   extern i_inputsytem* Inputsystem;


	
    }
