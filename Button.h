#pragma once

#include "Control.h"

class Button : virtual public Control
{
private:
	void(*m_CallBackFunc)(void);
public:
	Button(HWND & hWnd, HINSTANCE & hInstance, const char * text, unsigned short height, unsigned short width, unsigned short x, unsigned short y);
	~Button();
};

