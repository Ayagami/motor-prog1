#include "Engine.h"
#include <string>
#include "Window.h"
#include "Renderer.h"

using namespace Engn;

Engine::Engine(HINSTANCE hInst, int nCmdS, wstring t, int w, int h)
:hInstance(hInst),nCmdShow(nCmdS), _t(t), _w(w), _h(h), hWnd(0), WndC(new Window), Rendr(new Renderer){
	// So... Why so Serious?
}
void Engine::init(){
	// Hay que seguir esto...WndC;
}

void Engine::run(){

}
Engine::~Engine(){
	delete Rendr;
	Rendr = NULL;
	delete WndC;
	WndC = NULL;
}