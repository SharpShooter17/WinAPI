#include <cstdlib>
#include <initializer_list>
#include "WinAPI.hpp"
ComboBox * comb;
TextBox * text;
List * list;

void button(std::initializer_list<void*> list)
{
	MessageBox(nullptr, "Click", "Button", 0);
}

void combobox(std::initializer_list<void*> list)
{
	MessageBox(nullptr, "Change", "combobox", 0);
}

void isChecked(std::initializer_list<void*> list)
{
	CheckBox * check = (CheckBox*)list.begin();

	if (check->isChecked()) MessageBox(nullptr, "Checked", "combobox", 0);
	if (!check->isChecked()) MessageBox(nullptr, "UnChecked", "combobox", 0);
}

void test1()
{

}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	WinAPI::Initialize(hInstance, hPrevInstance, lpCmdLine, nCmdShow);
	Window * window = &WinAPI::getInstance().newWindow("New window", 1024, 768, RGB{ 239, 240, 241 });
	comb = &window->addComboBox(200,150,0,0);
	comb->addCallBackFunction(CBN_SELENDOK, combobox, {});
	comb->addItem("1");
	comb->addItem("2");

	text = &window->addTextBox(300, 400, 300, 0);

	list = &window->addList(200, 200, 600, 0);
	list->addItem("Hello!");
	list->addItem("World!");

	window->addLabel("My text", 30, 100, 5, 300);
	window->addIcon(Icon::mode::SHIELD, 48, 48, 5, 350);

	window->addButton("Click me!", 30, 150, 150, 0).addCallBackFunction(BN_CLICKED, button, {});
	CheckBox * ch = &window->addCheckBox("Check me!", 30, 100, 10, 40);
	ch->addCallBackFunction(BN_CLICKED, isChecked, { ch });

	window->Show();
	window->Update();
	window->Loop();
	return 0;
}
