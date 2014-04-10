//----------------
#include "Engine.h"
#include <iostream>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow){
	Engine myEngine(hInst, nCmdShow, "Test Engine", 640, 480);
	myEngine.init();
	myEngine.run();
}