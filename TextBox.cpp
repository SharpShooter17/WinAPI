#include "TextBox.h"

TextBox::TextBox(HWND & hWnd, HINSTANCE & hInstance, unsigned short height, unsigned short width, unsigned short x, unsigned short y) :
	Control(WS_EX_CLIENTEDGE, "EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL, x, y, height, width, hWnd, (HMENU)myId(), hInstance, NULL)
{
}

TextBox::~TextBox()
{
}

void TextBox::setText(const char * str)
{
	SetWindowText(Control::getHwnd(), str);
}

std::string TextBox::getText()
{
	DWORD size = GetWindowTextLength(Control::getHwnd());
	LPSTR Buffer = (LPSTR)GlobalAlloc(GPTR, size + 1);
	GetWindowText(Control::getHwnd(), Buffer, size + 1);

	std::string buffer(Buffer);
	GlobalFree(Buffer);
	return buffer;
}
