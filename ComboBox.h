#pragma once

#include <string>
#include "Control.h"

class ComboBox : public Control
{
public:
	ComboBox() = delete;
	ComboBox(HWND & hWnd, HINSTANCE & hInstance, unsigned short height, unsigned short width, unsigned short x, unsigned short y);
	~ComboBox();

	void				addItem(const char * item);
	std::string			getItem();
	unsigned int		getItemIndex();
};

