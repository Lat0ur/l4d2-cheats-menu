#pragma once
#include "tools.h"
#include "callvfunc.h"
typedef unsigned long HFont;

class color {
public:

	float r, g, b, a;

	color() {
		r = 0.f, g = 0.f, b = 0.f, a = 255.f;
	}

	color(float red, float green, float blue, float alpha) {
		r = red, g = green, b = blue, a = alpha;
	}

	color(float red, float green, float blue) {
		r = red, g = green, b = blue, a = 255.f;
	}
};
enum font_feature {
	FONT_FEATURE_ANTIALIASED_FONTS = 1, FONT_FEATURE_DROPSHADOW_FONTS = 2, FONT_FEATURE_OUTLINE_FONTS = 6
};

enum font_draw_type {
	FONT_DRAW_DEFAULT = 0, FONT_DRAW_NONADDITIVE, FONT_DRAW_ADDITIVE, FONT_DRAW_TYPE_COUNT = 2
};

enum FontFlags_t
{
	FONTFLAG_NONE,
	FONTFLAG_ITALIC = 0x001,
	FONTFLAG_UNDERLINE = 0x002,
	FONTFLAG_STRIKEOUT = 0x004,
	FONTFLAG_SYMBOL = 0x008,
	FONTFLAG_ANTIALIAS = 0x010,
	FONTFLAG_GAUSSIANBLUR = 0x020,
	FONTFLAG_ROTARY = 0x040,
	FONTFLAG_DROPSHADOW = 0x080,
	FONTFLAG_ADDITIVE = 0x100,
	FONTFLAG_OUTLINE = 0x200,
	FONTFLAG_CUSTOM = 0x400,
	FONTFLAG_BITMAP = 0x800,
};

    class surface 
    {
    public:

        void drawing_color(const int r, const int g, const int b, const int a)
        {
            tools::find_table<void(__thiscall*)(void*, int, int, int, int)>(this, 11)(this, r, g, b, a);
        }
		void draw_outline(int x0, int y0, int x1, int y1)
		{
			 tools::find_table<void(__thiscall*)(void*, int, int, int, int)>(this, 14)(this, x0, y0, x1, y1);
		}
		void draw_filled_rect(int x0, int y0, int x1, int y1)
		{
			
			tools::find_table<void(__thiscall*)(void*, int, int, int, int)>(this, 12)(this, x0, y0, x1, y1);
		}

        void text_color(const int r, const int g, const int b, const int a)
        {
            tools::find_table<void(__thiscall*)(void*, int, int, int, int)>(this, 19)(this, r, g, b, a);
        }

        void text_pos(const int x, const int y)
        {
            tools::find_table<void(__thiscall*)(void*, int, int)>(this, 20)(this, x, y);
        }

        void text_font(const unsigned long font)
        {
            tools::find_table<void(__thiscall*)(void*, unsigned long)>(this, 17)(this, font);
        }

        void draw_text(const wchar_t* text, const int len)
        {
            tools::find_table<void(__thiscall*)(void*, wchar_t const*, int, int)>(this, 22)(this, text, len, 0);
        }
		void DrawPrintText2(const wchar_t *text, int textLen, font_draw_type drawType)
		{
	
		 tools::find_table<void(__thiscall*)(void*, const wchar_t*, int, font_draw_type)>(this, 22)(this, text, textLen, drawType);
		}
		void SetCursorAlwaysVisible(bool visible)
		{
			typedef void(__thiscall* Fn)(void*, bool);
			return GetFunction<Fn>(this, 49)(this, visible);
		}

		HFont create_font()
		{
			typedef HFont(__thiscall* OriginalFn)(void*);
			return GetFunction<OriginalFn>(this, 63)(this);
		}
		bool SetFontGlyphSet(HFont font, const char* windowsFontName, std::int32_t tall, std::int32_t weight, std::int32_t blur, std::int32_t scanlines, std::int32_t flags, std::int32_t nRangeMin = 0, std::int32_t nRangeMax = 0)
		{
			typedef bool(__thiscall* OriginalFn)(void*, HFont, const char*, int, int, int, int, int, int, int);
			return GetFunction<OriginalFn>(this, 64)(this, font, windowsFontName, tall, weight, blur, scanlines, flags, nRangeMin, nRangeMax);
		}
		void DrawSetTextColor(int r, int g, int b, int a)
		{
			
			tools::find_table<void(__thiscall*)(void*, int, int, int, int)>(this, 19)(this, r, g, b, a);
		}
		void get_text_size(HFont font, const wchar_t *text, int &wide, int &tall)
		{
			typedef void(__thiscall* OriginalFn)(void*, HFont, const wchar_t*, int&, int&);
			return GetFunction<OriginalFn>(this, 72)(this, font, text, wide, tall);
		}

        void play_sound(const char* file)
        {
            tools::find_table<void(__thiscall*)(void*, const char*)>(this, 75)(this, file);
        }
		void draw_filled_rect_fade(int x0, int y0, int w, int h, size_t alpha0, size_t alpha1, bool horizontal) {
			
			tools::find_table<void(__thiscall*)(void*, int, int, int, int, size_t, size_t, bool)>(this, 115)(this, x0, y0, x0 + w, y0 + h, alpha0, alpha1, horizontal); 
		}
		
    };
