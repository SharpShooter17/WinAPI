#include "List.h"


List::List(HWND & hWnd, HINSTANCE & hInstance, unsigned short height, unsigned short width, unsigned short x, unsigned short y) :
	Control(WS_EX_CLIENTEDGE, "LISTBOX", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER, x, y, width, height, hWnd, (HMENU)myId(), hInstance, NULL)
{
}

List::~List()
{
}

void List::addItem(const char * str)
{
	SendMessage(Control::getHwnd(), LB_ADDSTRING, 0, (LPARAM) str);
}

std::string List::getItem()
{
	TCHAR  ListItem[256];
	SendMessage(Control::getHwnd(), (UINT)LB_GETTEXT, (WPARAM)getItemIndex(), (LPARAM)ListItem);
	return std::string(ListItem);
}

unsigned int List::getItemIndex()
{
	return SendMessage(Control::getHwnd(), (UINT)LB_GETCURSEL, (WPARAM)0, (LPARAM)0);
}
