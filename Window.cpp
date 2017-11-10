#include "Window.hpp"

LRESULT CALLBACK Window::InitialWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	if (Msg == WM_NCCREATE) {
		LPCREATESTRUCT create_struct = reinterpret_cast<LPCREATESTRUCT>(lParam);
		void * lpCreateParam = create_struct->lpCreateParams;
		Window * this_window = reinterpret_cast<Window *>(lpCreateParam);
		SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this_window));
		SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Window::WndProc));
		return this_window->realWndProc(hWnd, Msg, wParam, lParam);
	}
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

LRESULT CALLBACK Window::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	LONG_PTR user_data = GetWindowLongPtr(hWnd, GWLP_USERDATA);
	Window * this_window = reinterpret_cast<Window *>(user_data);
	return this_window->realWndProc(hWnd, Msg, wParam, lParam);
}

LRESULT Window::realWndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_COMMAND:
		//Callback functions
		for (int i = 0; i < mv_controls.size(); i++)
		{
			if ((HWND)(lParam) == mv_controls[i]->getHwnd())
			{
				for (int j = 0; j < mv_controls[i]->getNumOfEvents(); j++)
				{
					if (HIWORD(wParam) == mv_controls[i]->getEvent(j))
					{
						mv_controls[i]->callFunction(j);
						return 0;
					}
				}
			}

		}
		break;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}

	return 0;
}

Window::Window(	const char * nameWindow,
				int nCmdShow, 
				HINSTANCE hInstance, 
				unsigned short width, 
				unsigned short height,
				RGB BackgroundColor) :
	m_nameWindow(nameWindow),
	m_hwnd(nullptr),
	m_nCmdShow(nCmdShow),
	m_hInstance(hInstance)
{
	SetWindowLongPtr(m_hwnd, GWLP_WNDPROC, (LONG_PTR)(WndProc));

	WNDCLASSEX wc;

	wc.cbSize			=			sizeof(WNDCLASSEX);
	wc.style			=			0;
	wc.lpfnWndProc		=			&Window::InitialWndProc;
	wc.cbClsExtra		=			0;
	wc.cbWndExtra		=			0;
	wc.hInstance		=			hInstance;
	wc.hIcon			=			LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor			=			LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground	=			CreateSolidBrush(RGB(BackgroundColor.red, BackgroundColor.green, BackgroundColor.blue)); //(HBRUSH)(COLOR_WINDOW + 1); 
	wc.lpszMenuName		=			NULL;
	wc.lpszClassName	=			nameWindow;
	wc.hIconSm			=			LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc))
	{
		throw "Nie mo¿na zarejestrowac klasy okna!";
	}

	m_hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, nameWindow, nameWindow, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, hInstance, this);

	if (m_hwnd == NULL)
	{
		throw "Nie mo¿na utworzyæ okna.";
	}
}

Window::~Window()
{
	for (int i = 0; i < mv_controls.size(); i++)
	{
		delete mv_controls[i];
	}
}

void Window::Show()
{
	ShowWindow(m_hwnd, m_nCmdShow);
}

void Window::Hide()
{
	ShowWindow(m_hwnd, SW_HIDE);
}

void Window::Update()
{
	UpdateWindow(m_hwnd);
}

void Window::Loop()
{
	while (GetMessage(&m_msg, NULL, 0, 0))
	{
		TranslateMessage(&m_msg);
		DispatchMessage(&m_msg);
	}
}

Button & Window::addButton(const char * text, unsigned short height, unsigned short width, unsigned short x, unsigned short y)
{
	Control * temp = new Button(m_hwnd, m_hInstance, text, height, width, x, y);
	mv_controls.push_back( temp );
	return *dynamic_cast<Button*>(temp);
}

CheckBox & Window::addCheckBox(const char * text, unsigned short height, unsigned short width, unsigned short x, unsigned short y)
{
	Control * temp = new CheckBox(m_hwnd, m_hInstance, text, height, width, x, y);
	mv_controls.push_back(temp);
	return *dynamic_cast<CheckBox*>(temp);
}

Label & Window::addLabel(const char * str, unsigned short height, unsigned short width, unsigned short x, unsigned short y)
{
	Control * temp = new Label(m_hwnd, m_hInstance, str, height, width, x, y);
	mv_controls.push_back(temp);
	return *dynamic_cast<Label*>(temp);
}

Icon & Window::addIcon(Icon::mode mode, unsigned short height, unsigned short width, unsigned short x, unsigned short y)
{
	Control * temp = new Icon(m_hwnd, m_hInstance, mode, height, width, x, y);
	mv_controls.push_back(temp);
	return *dynamic_cast<Icon*>(temp);
}

ComboBox & Window::addComboBox(unsigned short height, unsigned short width, unsigned short x, unsigned short y)
{
	Control * temp = new ComboBox(m_hwnd, m_hInstance, height, width, x, y);
	mv_controls.push_back(temp);
	return *dynamic_cast<ComboBox*>(temp);
}

TextBox & Window::addTextBox(unsigned short height, unsigned short width, unsigned short x, unsigned short y)
{
	Control * temp = new TextBox(m_hwnd, m_hInstance, height, width, x, y);
	mv_controls.push_back(temp);
	return *dynamic_cast<TextBox*>(temp);
}

List & Window::addList(unsigned short height, unsigned short width, unsigned short x, unsigned short y)
{
	Control * temp = new List(m_hwnd, m_hInstance, height, width, x, y);
	mv_controls.push_back(temp);
	return *dynamic_cast<List*>(temp);
}
