#pragma once
#include "flags.h"
#include "move.h"
#include "button.h"
#include "user_cmd.h"
#include "interfaces.h"

	namespace render_manager 
	{
		namespace fonts 
		{
			extern HFont others_font;
			extern HFont esp_font;
			extern HFont menu_font;
			extern HFont minecraft_font;
			extern HFont tab_font;
			extern HFont cool_thing_font;
		}

		void init();
		void rect(int x, int y, int w, int h, color color);
		void filled_rect(int x, int y, int w, int h, color color);
		void vertical_gradient_rect(int x, int y, int w, int h, color top, color bottom);
		void horizontal_gradient_rect(int x, int y, int w, int h, color left, color right);
		void text(const char  *text, int x, int y, int font, color color);
	}

