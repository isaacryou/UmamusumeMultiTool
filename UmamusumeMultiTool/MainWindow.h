#pragma on
#include <windows.h>;
#include <tchar.h>;
#include <stdlib.h>;
#include <string.h>;

#define TIMER_FIND_UMAMUSUME_WINDOW 20
#define BUTTON_CAPTURE_SCREEN 10

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
);

LRESULT CALLBACK WndProc(
	_In_ HWND   hWnd,
	_In_ UINT   message,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);