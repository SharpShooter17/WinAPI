#include "Icon.h"

Icon::Icon(HWND & hWnd, HINSTANCE & hInstance, Icon::mode mode, unsigned short height, unsigned short width, unsigned short x, unsigned short y)
	: Control(0, "STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_ICON, x, y, width, height, hWnd, (HMENU)myId(), hInstance, NULL)
{
	setIcon(mode);
}


Icon::~Icon()
{
}

#undef ERROR

void Icon::setIcon(Icon::mode mode)
{
	switch (mode)
	{
	case Icon::mode::APPLICATION:	SendMessage(Control::getHwnd(), STM_SETICON, (WPARAM)LoadIcon(NULL, IDI_APPLICATION), 0);	break;
	case Icon::mode::INFORMATION:	SendMessage(Control::getHwnd(), STM_SETICON, (WPARAM)LoadIcon(NULL, IDI_INFORMATION), 0);	break;
	case Icon::mode::ERROR:			SendMessage(Control::getHwnd(), STM_SETICON, (WPARAM)LoadIcon(NULL, IDI_ERROR), 0);			break;
	case Icon::mode::WARNING:		SendMessage(Control::getHwnd(), STM_SETICON, (WPARAM)LoadIcon(NULL, IDI_WARNING), 0);		break;
	case Icon::mode::QUESTION:		SendMessage(Control::getHwnd(), STM_SETICON, (WPARAM)LoadIcon(NULL, IDI_QUESTION), 0);		break;
	case Icon::mode::SHIELD:		SendMessage(Control::getHwnd(), STM_SETICON, (WPARAM)LoadIcon(NULL, IDI_SHIELD), 0);		break;
	default:						SendMessage(Control::getHwnd(), STM_SETICON, (WPARAM)LoadIcon(NULL, IDI_WARNING), 0);		break;
	}
}

#define ERROR 0