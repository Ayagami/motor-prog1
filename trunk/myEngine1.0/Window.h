#pragma once

#include <iostream>
#include "myEngine_API.h"
#include <Windows.h>
using namespace std;
namespace dmr{
class MYENGINE_API Window{
public:
    static Window* CrearVentana( HINSTANCE hInstance ,int nCmdShow, wstring _t, int _w, int _h);
    Window() : m_hWnd( 0 ) {}
    ~Window();

private:
    static LRESULT CALLBACK WindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
    static const char * m_pszClassName;
    HWND m_hWnd;
};
}