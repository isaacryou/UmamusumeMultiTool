#include "WindowElements.h"

using namespace WindowElements;

//TextDisplayBox codes start here
TextDisplayBox::TextDisplayBox(HWND hWnd, HINSTANCE hInstance, int x, int y, int width, int height)
{
	CreateWindowEx(
		WS_EX_CLIENTEDGE,
		TEXT("Edit"), //Type of the window
		TEXT("Whatever"), //Text on the window
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

	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

TextDisplayBox::TextDisplayBox()
{

}
