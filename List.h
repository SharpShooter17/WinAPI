#pragma once

#include <string>
#include "Control.h"

class List : public Control
{
public:
	List(HWND & hWnd, HINSTANCE & hInstance, unsigned short height = 200, unsigned short width = 150, unsigned short x = 0, unsigned short y = 0);
	~List();

	void					addItem(const char * str);
	std::string				getItem();
	unsigned int			getItemIndex();
};

