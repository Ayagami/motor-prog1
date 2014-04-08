#include "DoMaRe.h"
#include <string>
using namespace dmr;
const char * dmr::DoMaRe::m_pszClassName = "DoMaRe";
DoMaRe * DoMaRe::CrearVentana( HINSTANCE hInst ,int nCmdShow, wstring _t, int _w, int _h) {

	WNDCLASS wincl = {0};
    if (!GetClassInfo(hInst, m_pszClassName, &wincl)) {
        
        wincl.hInstance = hInst;
        wincl.lpszClassName = m_pszClassName;
        wincl.lpfnWndProc = WindowProc; /*
		wincl.cbClsExtra = 0;
		wincl.cbWndExtra = 0;
		wincl.hIcon = NULL;
		wincl.hCursor = NULL;
		wincl.lpszMenuName = NULL;
		wincl.style = CS_HREDRAW | CS_VREDRAW; */
        wincl.hbrBackground = (HBRUSH)(COLOR_BTNFACE+1);
      
        if (RegisterClass(&wincl) == 0) {
            MessageBox(NULL,"The window class failed to register.","Error",0);
            return 0;
        }
    }

    DoMaRe * pDoMaRe = new DoMaRe;
	/* (char * )_t.c_str() */
	HWND hWnd = CreateWindow( m_pszClassName,(char * )_t.c_str(), WS_VISIBLE | WS_OVERLAPPEDWINDOW, 50, 50, _w + 8, _h + 30, NULL, NULL, hInst, pDoMaRe );
    if ( hWnd == NULL ) {
        delete pDoMaRe;
        MessageBox(NULL,"Problem creating the window.","Error",0); 
        return 0; 
    }

	ShowWindow(hWnd,nCmdShow);
    UpdateWindow(hWnd);

	//
	BOOL bRet;
    MSG msg;
    while( (bRet = GetMessage( &msg, 0, 0, 0 )) != 0){ 
        if (bRet == -1){
            // handle the error and possibly exit
        }
        else{
            TranslateMessage(&msg); 
            DispatchMessage(&msg); 
        }
    }


    return pDoMaRe;

}

 LRESULT CALLBACK DoMaRe::WindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam ) {
	 
    switch ( uMsg ) {
					
        case WM_NCCREATE: {
            CREATESTRUCT * pcs = (CREATESTRUCT*)lParam;
            DoMaRe * pDoMaRe = (DoMaRe*)pcs->lpCreateParams;
            pDoMaRe->m_hWnd = hwnd;
            SetWindowLongPtr( hwnd, GWLP_USERDATA, (LONG)pcs->lpCreateParams );
            return TRUE;
        }

        case WM_DESTROY: {
            DoMaRe * pDoMaRe = (DoMaRe *)GetWindowLongPtr( hwnd, GWLP_USERDATA );
            if ( pDoMaRe ) pDoMaRe->m_hWnd = 0;
			PostQuitMessage(0);
            break;
        }

        default:
            return DefWindowProc( hwnd, uMsg, wParam, lParam );

    }

    return 0;

}

DoMaRe::~DoMaRe() {
    if ( m_hWnd ) DestroyWindow( m_hWnd );
}