#pragma once
#include "Control.h"

class Icon :
	public Control
{
public:

#ifdef ERROR
	#undef ERROR
#endif // ERROR
	enum class mode
	{
		APPLICATION,
		INFORMATION,
		ERROR,
		WARNING,
		QUESTION,
		SHIELD		
	};
#ifndef ERROR
	#define ERROR 0
#endif // !ERROR

	Icon() = delete;
	Icon(HWND & hWnd, HINSTANCE & hInstance, Icon::mode mode, unsigned short height, unsigned short width, unsigned short x, unsigned short y);
	~Icon();

	void					setIcon( Icon::mode mode );
};


