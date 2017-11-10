#include "Label.h"

Label::Label(HWND & hWnd, HINSTANCE & hInstance, const char * str, unsigned short height, unsigned short width, unsigned short x, unsigned short y)
	: Control(0, "STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_LEFT, x, y, width, height, hWnd, (HMENU)myId(), hInstance, NULL)
{
	SetWindowText(Control::getHwnd(), str);
}


Label::~Label()
{
}
