#include "main.h"



    void main::begin(void* instance)
    {
		
        interfaces::setup();
        hooks::setup();
		render_manager::init();
    }
