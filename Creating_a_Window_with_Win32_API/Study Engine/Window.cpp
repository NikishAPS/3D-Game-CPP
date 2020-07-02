
#include "Window.h"

Window *window{};


LRESULT CALLBACK WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_CREATE:
		{
			window->OnCreate();
		}
		return 0;

		case WM_DESTROY:
		{
			window->OnDestroy();
			PostQuitMessage(0);
		}
		return 0;

		default:
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return NULL;
}


Window::Window()
{
}


bool Window::Init()
{
	WNDCLASSEX wc{ sizeof(WNDCLASSEX) };
	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW);
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hInstance = nullptr;
	wc.lpfnWndProc = WinProc;
	wc.lpszClassName = "MainWindowClass";
	wc.lpszMenuName = nullptr;
	wc.style = NULL;

	if (!RegisterClassEx(&wc))
	{
		printf("\nThe window class is not registered!\n");
		return false;
	}

	if (!window)
		window = this;

	hWnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, wc.lpszClassName, "Engine", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 400, 400, nullptr, nullptr, nullptr, nullptr);

	if (!hWnd)
	{
		printf("\nHWND is NULL!\n");
		return false;
	}

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	is_run = true;

	return true;
}

bool Window::Release()
{
	if (!DestroyWindow(hWnd))
		return false;
	return true;
}

bool Window::IsRun()
{
	return is_run;
}

void Window::OnCreate()
{
}

void Window::OnUpdate()
{
}

bool Window::Broadcast()
{
	MSG msg;

	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	window->OnUpdate();

	Sleep(0);

	return true;
}


void Window::OnDestroy()
{
	is_run = false;
}


Window::~Window()
{

}
