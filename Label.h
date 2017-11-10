#pragma once
#include "Control.h"
class Label :
	public Control
{
public:
	Label() = delete;
	Label(HWND & hWnd, HINSTANCE & hInstance, const char * str, unsigned short height, unsigned short width, unsigned short x, unsigned short y);
	~Label();
};

