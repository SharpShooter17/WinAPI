#include "CheckBox.h"


CheckBox::CheckBox(HWND & hWnd, HINSTANCE & hInstance, const char * text, unsigned short height, unsigned short width, unsigned short x, unsigned short y)
	:	Control(WS_EX_CLIENTEDGE, "BUTTON", text, WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, x, y, width, height, hWnd, (HMENU)myId(), hInstance, NULL),
		hwnd(hWnd)
{
}

CheckBox::~CheckBox()
{
}

bool CheckBox::isChecked()
{
	return IsDlgButtonChecked(hwnd, Control::myId());
}
