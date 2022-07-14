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
	this->messageToShow = textToShow;

	if (isReadonly == true)
	{
		TextOut(hdc,
			x, y,
			textToShow, _tcslen(textToShow));
	}
	else
	{
		CreateWindowEx(
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
}

TextDisplayBox::TextDisplayBox()
{

}
