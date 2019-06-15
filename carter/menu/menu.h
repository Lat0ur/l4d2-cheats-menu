#pragma once

#include <vector>
#include <memory>
#include <random>
#include <iostream>
#include <ShlObj_core.h>
#include <functional>
#include "..\render.h"


class c_menu {
public:
	bool menu_opened;
	vec2_t mouse_pos();
	bool mouse_in_params(int x, int y, int x2, int y2);
	void draw();
private:
	vec2_t _pos = vec2_t(500.f, 200.f);
	vec2_t _pos_radar = vec2_t(0.f, 0.f);
	int screen_width;
	int screen_height;
	int y_offset;
	int x_offset;
	int menu_alpha_main;
	int menu_alpha_text;
	int groupbox_scroll_add;
	int groupbox_width;
	int groupbox_bottom;
	int groupbox_top;
	int groupbox_outline_alpha;
	int checkbox_fade_alpha;
	bool is_color_tick_selected = false;
	std::string tooltip = "";

	void groupbox(int x, int y, int w, int h, std::string name, bool fade_thing);
	void checkbox(std::string name, bool* item, std::string tooltip);
	void combobox(int size, std::string name, std::string *itemname, int* item);
	void color_selector(std::string name, color* colour);
	void slider(int max, std::string name, int * item, std::string suffix, int step);
	//void keybind(int &item, std::string name);
	void text(std::string text_to_write);

	RECT get_text_size(DWORD font, const char* text, ...)
	{
		size_t origsize = strlen(text) + 1;
		const size_t newsize = 100;
		size_t convertedChars = 0;
		wchar_t wcstring[newsize];
		mbstowcs_s(&convertedChars, wcstring, origsize, text, _TRUNCATE);

		RECT rect; int x, y;
		interfaces::surface_interface->get_text_size(font, wcstring, x, y);
		rect.left = x; rect.bottom = y;
		rect.right = x;
		return rect;
	}
};

extern c_menu menu;