#pragma once
#include <stdlib.h>;
#include <string>;
#include <windows.h>;
#include <tchar.h>;

namespace WindowElements
{
	class WindowHelper
	{
	public: 
		static std::string GetActiveWindowTitleString();
		static void GetWindowPos(HWND, int*, int*);
	};

	class TextDisplayBox
	{
	public:
		TextDisplayBox();
		TextDisplayBox(HWND, HINSTANCE, HDC, int, int, int, int, bool = false, std::string = "");

		void UpdateDisplayValue(std::string = "");

	private:
		int x;
		int y;
		int width;
		int height;
		HWND textDisplayBox;
	};

	class SearchBox
	{
	public:
		SearchBox(HWND, int, int, int, int);

	private:
		int x;
		int y;
		int width;
		int height;
		std::string searchText;
	};

	class IconDisplayBox
	{
	public:
	private:
		int x;
		int y;
		int width;
		int height;
		bool iconRemovable;
		//Come up with a way to store array of selected icons (Maybe list of ids)
	};

	class WindowTab
	{
	public:
	private:
	};

	class ResetButton
	{
	public:
		ResetButton(HWND, int, int, int, int);
	};
}

