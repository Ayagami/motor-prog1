#pragma once

#include <iostream>
#include "myEngine_API.h"
#include <Windows.h>
using namespace std;

class MYENGINE_API DoMaRe{
public:
    static DoMaRe* CrearVentana( HINSTANCE hInstance ,int nCmdShow, wstring _t, int _w, int _h);
    DoMaRe() : m_hWnd( 0 ) {}
    ~DoMaRe();

private:
    static LRESULT CALLBACK WindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
    static const char * m_pszClassName;
    HWND m_hWnd;
};
