#include "DoMaRe.h"
#include <string>
const char * DoMaRe::m_pszClassName = "DoMaRe";

DoMaRe * DoMaRe::CrearVentana( HINSTANCE hInst ,int nCmdShow, wstring _t, int _w, int _h) {

    WNDCLASS wincl;
    if (!GetClassInfo(hInst, m_pszClassName, &wincl)) {
        wincl.style = CS_HREDRAW | CS_VREDRAW;
        wincl.hInstance = hInst;
        wincl.lpszClassName = m_pszClassName;
        wincl.lpfnWndProc = WindowProc;
        wincl.cbClsExtra = 0;
        wincl.cbWndExtra = 0;
        wincl.hIcon = NULL;
        wincl.hCursor = NULL;
        wincl.hbrBackground = (HBRUSH)(COLOR_BTNFACE+1);
        wincl.lpszMenuName = NULL;
        if (RegisterClass(&wincl) == 0) {
            MessageBox(NULL,"The window class failed to register.","Error",0);
            return 0;
        }
    }

    DoMaRe * pDoMaRe = new DoMaRe;
	HWND hWnd = CreateWindow( m_pszClassName, (char * )_t.c_str(), WS_VISIBLE | WS_OVERLAPPEDWINDOW, 50, 50, _w, _h, NULL, NULL, hInst, pDoMaRe );
    if ( hWnd == NULL ) {
        delete pDoMaRe;
        MessageBox(NULL,"Problem creating the window.","Error",0); 
        return 0; 
    }

	ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);

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