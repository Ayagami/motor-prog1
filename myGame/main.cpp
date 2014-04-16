//----------------
#include "Engine.h"
#include "Juego.h"
#include <iostream>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow){
	DoMaRe::Engine myEngine(hInst, nCmdShow, "Damian's Quest: Heroes Reborn", 640, 480);
	myEngine.init();
	myEngine.G = new MiJuego::Juego();
	myEngine.run();
}