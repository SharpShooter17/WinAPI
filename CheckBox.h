#pragma once
#include "Control.h"
class CheckBox : public Control
{
private:
	HWND & hwnd;
public:
	CheckBox(HWND & hWnd, HINSTANCE & hInstance, const char * text, unsigned short height, unsigned short width, unsigned short x, unsigned short y);
	~CheckBox();

	bool isChecked();
};

