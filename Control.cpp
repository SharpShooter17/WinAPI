#include "Control.h"

unsigned int Control::countControl = 0;

const HWND & Control::getHwnd()
{
	return m_ControlHwnd;
}

unsigned int Control::myId()
{
	return m_id;
}

int Control::getWidth()
{
	return m_width;
}

int Control::getHeight()
{
	return m_height;
}

int Control::getX()
{
	return m_pos_x;
}

int Control::getY()
{
	return m_pos_y;
}

void Control::addCallBackFunction(int Event, void(*callBackFunction)(std::initializer_list<void*>), std::initializer_list<void*> list)
{
	mv_callBack.push_back(callback_t{ Event, callBackFunction, list });
}

int Control::getNumOfEvents()
{
	return mv_callBack.size();
}

int Control::getEvent(int index)
{
	return mv_callBack[index].event;
}

void Control::callFunction(int index)
{
	mv_callBack[index].callBack(mv_callBack[index].list);
}

void Control::setHwnd(const HWND & hwnd)
{
	m_ControlHwnd = hwnd;
}

Control::Control(	int exStyle,
					const char * className,
					const char * windowName,
					int style,
					int x,
					int y,
					int width,
					int height,
					HWND hParent,
					HMENU hMenu,
					HINSTANCE hInstance,
					void * lParm) :
	m_pos_x(x),
	m_pos_y(y),
	m_width(width),
	m_height(height)
{
	m_id = countControl;
	countControl++;
	m_ControlHwnd = CreateWindowEx(exStyle, className, windowName, style, x, y, width, height, hParent, hMenu, hInstance, lParm);
}

Control::~Control()
{
}
