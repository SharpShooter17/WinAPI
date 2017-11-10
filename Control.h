#pragma once

#include <Windows.h>
#include <vector>
#include <utility>
#include <initializer_list>

class Control
{
private:
	static unsigned int						countControl;
	unsigned int							m_id;
	HWND									m_ControlHwnd;
	int										m_pos_x;
	int										m_pos_y;
	int										m_height;
	int										m_width;
	void									setHwnd(const HWND & hwnd);
	struct callback_t {
		int event;
		void(*callBack)(std::initializer_list<void*>);
		std::initializer_list<void*> list;
	};
	///First parametr is event, second is function, third parameter is a parameter to function
	std::vector<callback_t>	mv_callBack;
public:
	Control() = delete;
	Control(	int exStyle, 
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
				void * lParm );
	virtual ~Control();
	const HWND		&		getHwnd();
	unsigned int			myId();
	int						getWidth();
	int						getHeight();
	int						getX();
	int						getY();
	
	//Event description: https://msdn.microsoft.com/pl-pl/library/windows/desktop/ms644927(v=vs.85).aspx#system_defined
	void					addCallBackFunction(int Event, void(*callBackFunction)(std::initializer_list<void*>), std::initializer_list<void*> list);
	int						getNumOfEvents();
	int						getEvent(int index);
	void					callFunction(int index);
};

