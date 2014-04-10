#pragma once
#include "Engine.h"
#include <string>
#include "Window.h"
#include "Renderer.h"

Engine::Engine(HINSTANCE hInst, int nCmdS, string t, int w, int h):
hInstance(hInst),nCmdShow(nCmdS), _t(t), _w(w), _h(h), hWnd(0), WndC(new Window(hInst) ), Rendr(new Renderer){
	// So... Why so Serious?
}
bool Engine::init(){
	if(WndC->CrearVentana(_t,_w,_h) == TRUE && Rendr->Init(WndC->hWnd()) == TRUE)
		return true;
	return false;
}

void Engine::run(){
	bool grs = true;
	MSG Mess;
	while(grs){
		if(PeekMessage(&Mess,NULL,0,0,PM_REMOVE)){
			TranslateMessage(&Mess);
			DispatchMessage(&Mess);
		}
		if(Mess.message == WM_QUIT)
			grs = false;
		Rendr->BeginFrame();
		Rendr->EndFrame();
	}
}
Engine::~Engine(){
	delete Rendr;
	Rendr = NULL;
	delete WndC;
	WndC = NULL;
}