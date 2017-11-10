#include "WinAPI.hpp"

WinAPI * WinAPI::mptr_WinAPI = nullptr;

WinAPI::WinAPI()
{

}

WinAPI::WinAPI(const HINSTANCE & hInstance, const HINSTANCE & hPrevInstance, const LPSTR & lpCmdLine, const int & nCmdShow) :
	hInstance(hInstance),
	hPrevInstance(hPrevInstance),
	nCmdShow(nCmdShow)
{

}

WinAPI::~WinAPI()
{
	for (unsigned i = 0; i < mv_windows.size(); i++)
		delete mv_windows[i];

	delete mptr_WinAPI;
	mptr_WinAPI = nullptr;
}

WinAPI & WinAPI::getInstance()
{
	if (mptr_WinAPI == nullptr)
	{
		throw "Nie zainicjowano bilioteki WinAPI!";
	}
	return *mptr_WinAPI;
}

void WinAPI::Initialize(const HINSTANCE & hInstance, const HINSTANCE & hPrevInstance, const LPSTR & lpCmdLine, const int & nCmdShow)
{
	if (mptr_WinAPI == nullptr)
	{
		mptr_WinAPI = new WinAPI(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
	}
	else
	{
		throw "Bibliotek zostala juz zainicjowana!";
	}
}

Window & WinAPI::newWindow(const char * nameWindow, unsigned short width, unsigned short height, RGB BackgroundColor)
{
	Window * window = new Window(nameWindow, nCmdShow, hInstance, width, height, BackgroundColor);
	
	if (window == nullptr)
	{
		throw "Brak pamieci!";
	}

	mv_windows.push_back(window);
	
	return *window;
}

Window & WinAPI::operator[](unsigned n)
{
	if (n >= mv_windows.size())
		throw "out of rnage";
	return *mv_windows[n];
}

unsigned WinAPI::countWindows()
{
	return mv_windows.size();
}
