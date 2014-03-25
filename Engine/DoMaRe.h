#ifndef TEST2
#define TEST2
#include <iostream>
#include <Windows.h>
using namespace std;


class Test2{
public:
	HWND _hWND;
	HINSTANCE _hInst;
	wstring _titulo;
	int w;
	int h;
	Test2(wstring _t, int _w, int _h){
		_titulo = _t;
		w = _w;
		h = _h;
	}
	void setHWND(HWND p){
		_hWND = p;
	}
	void setHinstance(HINSTANCE _p){
		_hInst = _p;
	}
	
};
#endif