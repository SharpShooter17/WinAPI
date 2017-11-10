#pragma once

#include <Windows.h>
#include <vector>

#include "Window.hpp"

class WinAPI
{
private:
	WinAPI();
	WinAPI(const HINSTANCE & hInstance, const HINSTANCE & hPrevInstance, const LPSTR & lpCmdLine, const int & nCmdShow);
	~WinAPI();

	std::vector<Window *>	mv_windows;

	HINSTANCE				hInstance;
	HINSTANCE				hPrevInstance;
	int						nCmdShow;

	static WinAPI	*		mptr_WinAPI;
public:
	static WinAPI	&		getInstance();
	static void				Initialize(const HINSTANCE & hInstance, const HINSTANCE & hPrevInstance, const LPSTR & lpCmdLine, const int & nCmdShow);
	Window			&		newWindow(const char * nameWindow, unsigned short width = 1024, unsigned short height = 768, RGB BackgroundColor = RGB{ 255, 255, 255 });
	Window			&		operator[](unsigned n);
	unsigned				countWindows();
};

