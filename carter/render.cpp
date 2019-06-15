#include "render.h"

#define FW_DONTCARE         0
#define FW_THIN             100
#define FW_EXTRALIGHT       200
#define FW_LIGHT            300
#define FW_NORMAL           400
#define FW_MEDIUM           500
#define FW_SEMIBOLD         600
#define FW_BOLD             700
#define FW_EXTRABOLD        800
#define FW_HEAVY            900

	namespace render_manager 
	{
		namespace fonts {
			HFont others_font;
			HFont esp_font;
			HFont menu_font;
			HFont minecraft_font;
			HFont tab_font;
			HFont cool_thing_font;
		}
	}

	void render_manager::init() 
	{
		//SetCursorAlwaysVisible

		fonts::others_font = interfaces::surface_interface->create_font();
		fonts::esp_font = interfaces::surface_interface->create_font();
		fonts::menu_font = interfaces::surface_interface->create_font();
		fonts::minecraft_font = interfaces::surface_interface->create_font();
		fonts::tab_font = interfaces::surface_interface->create_font();
		fonts::cool_thing_font = interfaces::surface_interface->create_font();

		interfaces::surface_interface->SetFontGlyphSet(fonts::others_font, "Small Fonts", 8, 400, 0, 0, FONTFLAG_OUTLINE);
		interfaces::surface_interface->SetFontGlyphSet(fonts::esp_font, "Verdana", 13, 50, 0, 0, FONTFLAG_DROPSHADOW);
		interfaces::surface_interface->SetFontGlyphSet(fonts::menu_font, "Verdana", 12, 0, 0, 0, FONTFLAG_DROPSHADOW);
		interfaces::surface_interface->SetFontGlyphSet(fonts::tab_font, "cherryfont", 23, 0, 0, 0, FONTFLAG_ANTIALIAS);
		interfaces::surface_interface->SetFontGlyphSet(fonts::cool_thing_font, "Verdana", 25, 0, 0, 0, FONTFLAG_ANTIALIAS);
		interfaces::surface_interface->SetFontGlyphSet(fonts::minecraft_font, "Minecraft", 19, 0, 0, 0, FONTFLAG_DROPSHADOW);


	}

	void render_manager::rect(int x, int y, int w, int h, color color) {
		interfaces::surface_interface->drawing_color(color.r, color.g, color.b, color.a);
		interfaces::surface_interface->draw_outline(x, y, x + w, y + h);
	}

	void render_manager::filled_rect(int x, int y, int w, int h, color color) {
		interfaces::surface_interface->drawing_color(color.r, color.g, color.b, color.a);
		interfaces::surface_interface->draw_filled_rect(x, y, x + w, y + h);
	}

	void render_manager::vertical_gradient_rect(int x, int y, int w, int h, color top, color bottom) {
		interfaces::surface_interface->drawing_color(top.r, top.g, top.b, top.a);
		interfaces::surface_interface->draw_filled_rect_fade(x, y, w, h, 255, 255, false);
		interfaces::surface_interface->drawing_color(bottom.r, bottom.g, bottom.b, bottom.a);
		interfaces::surface_interface->draw_filled_rect_fade(x, y, w, h, 0, 255, false);
	}

	void render_manager::horizontal_gradient_rect(int x, int y, int w, int h, color left, color right) {
		interfaces::surface_interface->drawing_color(left.r, left.g, left.b, left.a);
		interfaces::surface_interface->draw_filled_rect_fade(x, y, w, h, 255, 255, true);
		interfaces::surface_interface->drawing_color(right.r, right.g, right.b, right.a);
		interfaces::surface_interface->draw_filled_rect_fade(x, y, w, h, 0, 255, true);
	}

	void render_manager::text(const char* text, int x, int y, int font, color color) {
		std::string text_normal = text;
		std::wstring text_wide = std::wstring(text_normal.begin(), text_normal.end());
		const wchar_t* final_text = text_wide.c_str();

		interfaces::surface_interface->DrawSetTextColor(color.r, color.g, color.b, color.a);
		interfaces::surface_interface->text_font(font);
		interfaces::surface_interface->text_pos(x, y);
		interfaces::surface_interface->DrawPrintText2(final_text, wcslen(final_text), FONT_DRAW_DEFAULT);
	}
