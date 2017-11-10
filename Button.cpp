#include "Button.h"

Button::Button(HWND & hWnd, HINSTANCE & hInstance, const char * text,unsigned short height, unsigned short width, unsigned short x, unsigned short y) : 
	Control(WS_EX_CLIENTEDGE, "BUTTON", text, WS_CHILD | WS_VISIBLE, x, y, width, height, hWnd, (HMENU)myId(), hInstance, NULL)
{
}

Button::~Button()
{
}