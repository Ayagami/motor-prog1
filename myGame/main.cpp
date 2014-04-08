//----------------
#include "Window.h"
#include "myEngine_API.h"
#include <iostream>

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow){
    dmr::Window * pviewvars = dmr::Window::CrearVentana( hInstance ,nCmdShow, (L"Prueba"), 500, 200);
    if ( pviewvars == 0 ) return 0;
    delete pviewvars;
    return 0;
}