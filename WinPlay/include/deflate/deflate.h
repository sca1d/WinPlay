#pragma once

#ifndef DLL_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#endif

#ifndef _DEF_WINFO
struct _winfo {

	HINSTANCE	hInst;
	HWND		hwnd;
	HDC			hdc;

	/*
	_winfo(HINSTANCE _hInst, HWND _hwnd, HDC _hdc) {
		hInst = _hInst;
		hwnd = _hwnd;
		hdc = _hdc;
	}
	*/

};
typedef struct _winfo winfo;
#define _DEF_WINFO
#endif
