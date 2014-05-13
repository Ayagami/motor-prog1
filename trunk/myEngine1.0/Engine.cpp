#pragma once
#include "Engine.h"
#include <string>
#include "Window.h"
#include "Renderer.h"
#include "Game.h"
#include "input\pg1_directinput.h"
using namespace DoMaRe;
Engine::Engine(HINSTANCE hInst, int nCmdS, std::string t, int w, int h):
hInstance(hInst),nCmdShow(nCmdS), _t(t), _w(w), _h(h), hWnd(0), WndC(new Window(hInst) ), Rendr(new Renderer), G(NULL), dInput( new DirectInput() ){
	// So... Why so Serious?
}
bool Engine::init(){
	if(WndC->CrearVentana(_t,_w,_h) == TRUE && Rendr->Init(WndC->hWnd()) == TRUE && dInput->init(hInstance,WndC->hWnd()) == TRUE)
		return true;
	return false;
}

void Engine::run(){
	//bool grs = true;
	MSG Mess;

	if(!G) return;
	if(!G->Init(*Rendr)) return;
	while(G->getGame()){
		dInput->reacquire();

		Rendr->BeginFrame();
		G->Frame(*Rendr, *dInput);
		Rendr->EndFrame();
		
		if(PeekMessage(&Mess,NULL,0,0,PM_REMOVE)){
			TranslateMessage(&Mess);
			DispatchMessage(&Mess);
		}
		if(Mess.message == WM_QUIT)
			G->setGame(false);
	}
}
Engine::~Engine(){
	if(dInput){
	delete dInput;
	dInput = NULL;
	}
	if(G){
	delete G;
	G = NULL;
	}
	if(Rendr){
	delete Rendr;
	Rendr = NULL;
	}
	if(WndC){
	delete WndC;
	WndC = NULL;
	}
}