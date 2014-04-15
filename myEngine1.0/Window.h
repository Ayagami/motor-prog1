#pragma once
#include <iostream>
#include "myEngine_API.h"
#include <Windows.h>
using namespace std;
class Window{

public:
    bool CrearVentana(string _t, int _w, int _h);
	HWND hWnd(){
		return m_hWnd;
	}
	static LRESULT CALLBACK WindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
    Window(HINSTANCE hInstance);
    ~Window();
	
private:
	WNDCLASS * WC;
	HINSTANCE _hInst;
	HWND m_hWnd;
	char* m_pszClassName;
};