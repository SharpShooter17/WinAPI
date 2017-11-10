#pragma once
#include <string>
#include "Control.h"
class TextBox :	public Control
{
public:
	TextBox(HWND & hWnd, HINSTANCE & hInstance, unsigned short height = 200, unsigned short width = 150, unsigned short x = 0, unsigned short y = 0);
	~TextBox();
	void setText(const char * str);
	std::string getText();
};

