#pragma once
#include <Windows.h>
#include <vector>
#include "Button.h"
#include "CheckBox.h"
#include "ComboBox.h"
#include "TextBox.h"
#include "List.h"
#include "Label.h"
#include "Icon.h"

struct RGB
{
	unsigned char red, green, blue;
};

class Window
{
private:
	const char	*			m_nameWindow;
	HWND					m_hwnd;
	MSG						m_msg;
	int						m_nCmdShow;	
	HINSTANCE				m_hInstance;

	std::vector<Control*>	mv_controls;

	static LRESULT CALLBACK	InitialWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK	WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
		   LRESULT			realWndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
public:
	Window(const char * nameWindow, int nCmdShow, HINSTANCE hInstance, unsigned short width = 1024, unsigned short height = 768, RGB BackgroundColor = RGB{ 255, 255, 255 });
	Window() = delete;
	~Window();

	void					Show();
	void					Hide();
	void					Update();
	void					Loop();

	Button		&			addButton		(const char * text = "Button", unsigned short height = 30, unsigned short width = 150, unsigned short x = 0, unsigned short y = 0);
	CheckBox	&			addCheckBox		(const char * text = "CheckBox", unsigned short height = 30, unsigned short width = 150, unsigned short x = 0, unsigned short y = 0);
	Label		&			addLabel		(const char * str = "Label", unsigned short height = 200, unsigned short width = 150, unsigned short x = 0, unsigned short y = 0);
	Icon		&			addIcon			(Icon::mode mode = Icon::mode::APPLICATION, unsigned short height = 200, unsigned short width = 150, unsigned short x = 0, unsigned short y = 0);
	ComboBox	&			addComboBox		(unsigned short height = 200, unsigned short width = 150, unsigned short x = 0, unsigned short y = 0);
	TextBox		&			addTextBox		(unsigned short height = 200, unsigned short width = 150, unsigned short x = 0, unsigned short y = 0);
	List		&			addList			(unsigned short height = 200, unsigned short width = 150, unsigned short x = 0, unsigned short y = 0);
};

