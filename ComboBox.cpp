#include "ComboBox.h"

ComboBox::ComboBox(HWND & hWnd, HINSTANCE & hInstance, unsigned short height, unsigned short width, unsigned short x, unsigned short y) :
	Control(WS_EX_CLIENTEDGE, "COMBOBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | CBS_DROPDOWNLIST, x, y, width, height, hWnd, (HMENU)myId(), hInstance, NULL)
{
}

void ComboBox::addItem(const char * item)
{
	SendMessage(Control::getHwnd(), CB_ADDSTRING, 0, (LPARAM) item);
}

std::string ComboBox::getItem()
{
	TCHAR  ListItem[256];
	SendMessage(Control::getHwnd(), (UINT)CB_GETLBTEXT, (WPARAM)getItemIndex(), (LPARAM)ListItem);
	return std::string(ListItem);
}

unsigned int ComboBox::getItemIndex()
{
	return SendMessage(Control::getHwnd(), (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
}


ComboBox::~ComboBox()
{
}
