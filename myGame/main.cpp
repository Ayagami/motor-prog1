//----------------
#include "DoMaRe.h"
#include "myEngine_API.h"
#include <iostream>

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow){
    DoMaRe * pviewvars = DoMaRe::CrearVentana( hInstance ,nCmdShow, (L"Prueba"), 500, 200);
    if ( pviewvars == 0 ) return 0;
    delete pviewvars;
    return 0;

}