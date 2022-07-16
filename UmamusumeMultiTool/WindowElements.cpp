#include "WindowElements.h"

using namespace WindowElements;

//TextDisplayBox codes start here
TextDisplayBox::TextDisplayBox(HWND hWnd, HINSTANCE hInstance, HDC hdc, int x, int y, int width, int height, bool isReadonly, std::string _textToShow)
{
	TCHAR* textToShow = new TCHAR[_textToShow.size() + 1];
	textToShow[_textToShow.size()] = 0;
	std::copy(_textToShow.begin(), _textToShow.end(), textToShow);

	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	if (isReadonly == true)
	{
		TextOut(hdc,
			x, y,
			textToShow, _tcslen(textToShow));
	}
	else
	{
		this->textDisplayBox = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			TEXT("Edit"), //Type of the window
			textToShow, //Text on the window
			WS_CHILD | WS_VISIBLE | WS_BORDER,
			x, //X
			y, //Y
			width, //Width
			height, //Height
			hWnd,
			NULL,
			hInstance,
			NULL
		);
	}

	delete[] textToShow;
}

TextDisplayBox::TextDisplayBox()
{

}

void TextDisplayBox::UpdateDisplayValue(std::string _textToUpdate)
{
	SetWindowTextA(
		this->textDisplayBox,
		_textToUpdate.c_str()
	);
}

std::string WindowHelper::GetActiveWindowTitleString()
{
	char wnd_title[256];
	HWND hwnd = GetForegroundWindow();
	GetWindowTextA(hwnd, wnd_title, sizeof(wnd_title));
	return wnd_title;
}

void WindowHelper::GetWindowPos(HWND _hwnd, int* _x, int* _y)
{
	RECT rect = { NULL };
	if (GetWindowRect(_hwnd, &rect))
	{
		*_x = rect.left;
		*_y = rect.top;
	}
}