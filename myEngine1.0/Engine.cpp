#pragma once
#include <sstream>
#include "Engine.h"
#include <string>
#include "Renderer\Window.h"
#include "Renderer\Renderer.h"
#include "Game.h"
#include "timer\pg1_timer.h"
#include "input\pg1_directinput.h"
#include "Scene\Import.h"
#include "Scene\Scene.h"
using namespace DoMaRe;
Engine::Engine(HINSTANCE hInst, int nCmdS, std::string t, int w, int h):
hInstance(hInst),nCmdShow(nCmdS), _t(t), _w(w), _h(h), hWnd(0), WndC(new Window(hInst) ), Rendr(new Renderer), G(NULL), dInput( new DirectInput() ), m_pkTimer( new Timer() ){
	// So... Why so Serious?
}
bool Engine::init(){
	if(WndC->CrearVentana(_t,_w,_h) == TRUE && Rendr->Init(WndC->hWnd()) == TRUE && dInput->init(hInstance,WndC->hWnd()) == TRUE){
		Import* importer = new Import();
		importer->SetRenderer(Rendr);
		//Import::SetRenderer(Rendr);
		return true;
	}
	return false;
}

void Engine::run(){
	//bool grs = true;
	MSG Mess;

	if(!G) return;
	if(!G->Init(*Rendr)) return;
	m_pkTimer->firstMeasure();

	while(G->getGame()){

		m_pkTimer->measure();
		static std::stringstream Title;
		Title.str("");
		Title << WndC->getWindowName()<< " (" << m_pkTimer->fps() << " FPS)";

		WndC->setWindowName(Title.str());

		dInput->reacquire();
		Rendr->BeginFrame();
		G->Frame(*Rendr, *dInput, *m_pkTimer);
		G->currentScene().Frame(*Rendr);
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
	if(m_pkTimer){
	delete m_pkTimer;
	m_pkTimer = NULL;
	}

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