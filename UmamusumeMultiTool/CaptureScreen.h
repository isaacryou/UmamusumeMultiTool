#pragma once
#include <Windows.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

namespace CaptureScreen
{
	class CaptureWindowForOcr
	{
	public:
		static cv::Mat CaptureWindow(HWND, int, int, int, int);
	private:
		static BITMAPINFOHEADER createBitmapHeader(int, int);
	};
}