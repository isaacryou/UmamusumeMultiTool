#pragma once
#include <stdlib.h>;
#include <string>;
#include <windows.h>;

namespace WindowElements
{
	class TextDisplayBox
	{
	public:
		TextDisplayBox();
		TextDisplayBox(HWND, HINSTANCE, int, int, int, int);

	private:
		int x;
		int y;
		int width;
		int height;
		std::string message;
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

