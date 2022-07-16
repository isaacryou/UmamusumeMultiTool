#include "MainWindow.h"
#include "WindowElements.h"

const int windowWidth = 960;
const int windowHeight = 540;
const int numberOfTextDisplayBoxes = 5; //Defines the number of boxes that will show the text
const int textBoxInitialX = 100;
const int textBoxInitialY = 20;
const int textBoxInitialWidth = 100;
const int textBoxInitialHeight = 20;
const int textBoxDistanceBetweenY = 40;

static TCHAR szWindowClass[] = _T("UMT");
static TCHAR szTitle[] = _T("Umamusume Multitool");

WindowElements::TextDisplayBox textDisplayBoxes[numberOfTextDisplayBoxes];

HINSTANCE hInst;

HWND hwndCaptureButton;
HWND hwndTextBox;

//This is the function that creates the window
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
    /*
    * Structure containing info about the window
    */
    WNDCLASSEX wcex;

    /*
    * cbSize: The size in bytes
    * style: Class style
    * lpfnWndProc: A pointer to the window procedure
    * cbClsExtra: The number of extra bytes to allocate following the window-class structure
    * cbWndExtra: The number of extra bytes to allocate following the window instance
    * hInstance: A handle to the instance that contains the window procedure for the class
    * hIcon: A handle to the class icon
    * hCursor: A handle to the class cursor
    * hbrBackground: A handle to the class background brush
    * lpszMenuName: Pointer to a null-terminated character string that specific the resource name of the class menu
    * lpszClassName: A point to a null-terminated string or is an atom
    * hIconSm: A handle to a small icon that is associated with the window class
    */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Umamusume Multitool Main Window"),
            NULL);

        return 1;
    }

    // Store instance handle in our global variable
    hInst = hInstance;

    // The parameters to CreateWindowEx explained:
    // WS_EX_OVERLAPPEDWINDOW : An optional extended window style.
    // szWindowClass: the name of the application
    // szTitle: the text that appears in the title bar
    // WS_OVERLAPPEDWINDOW: the type of window to create
    // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
    // 500, 100: initial size (width, length)
    // NULL: the parent of this window
    // NULL: this application dows not have a menu bar
    // hInstance: the first parameter from WinMain
    // NULL: not used in this application
    HWND hWnd = CreateWindowEx(
        WS_EX_OVERLAPPEDWINDOW,
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        windowWidth, windowHeight,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Umamusume Multitool Main Window"),
            NULL);

        return 1;
    }

    hwndCaptureButton = CreateWindow(
        L"BUTTON",  // Predefined class; Unicode assumed 
        L"Capture Screen",      // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        200,         // x position 
        10,         // y position 
        100,        // Button width
        100,        // Button height
        hWnd,     // Parent window
        (HMENU)BUTTON_CAPTURE_SCREEN,       // No menu.
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE),
        NULL);      // Pointer not needed.


    // The parameters to ShowWindow explained:
    // hWnd: the value returned from CreateWindow
    // nCmdShow: the fourth parameter from WinMain
    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);

    // Main message loop:
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return

//This is the function that handles with what is done and what needs to be done on the window
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);

        WindowElements::TextDisplayBox::TextDisplayBox(hWnd, hInst, hdc, 100, 100, 100, 100, true, "Read only text");

        textDisplayBoxes[0] = WindowElements::TextDisplayBox::TextDisplayBox(
            hWnd,
            hInst,
            hdc,
            100, 150,
            500,
            300, false, "");

        EndPaint(hWnd, &ps);
        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case BUTTON_CAPTURE_SCREEN:
            textDisplayBoxes[0].UpdateDisplayValue("Updated through button");
            break;
        }

        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }

    return 0;
}