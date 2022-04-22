#include <Windows.h>

#include "deflate/deflate.h"
#include "WindowInfo.h"

DLL_EXPORT winfo MakeNewWindow(char* name, WNDPROC wndproc) {

	HINSTANCE hInst = GetModuleHandle(NULL);

	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = wndproc == NULL ? DefWindowProc : wndproc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = name;

	if (!RegisterClass(&wc)) {
		winfo info = { NULL, NULL, NULL };
		return info;
	}

	HWND hwnd = CreateWindow(
		name, name,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL,
		hInst, NULL);

	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	winfo info = { hInst, hwnd, GetDC(hwnd) };
	return info;

}
