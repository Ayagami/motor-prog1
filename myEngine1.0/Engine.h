#pragma once
#include <iostream>
#include "myEngine_API.h"
class Window;
class Renderer;
#include <Windows.h>
using namespace std;
namespace Engn{
	class MYENGINE_API Engine{

		public:
			Engine(HINSTANCE hInst ,int nCmdS, wstring t, int w, int h, char* s);
			~Engine();
			bool init();
			void run();
			HWND hWnd;

		private:
			char* clase;
			HINSTANCE hInstance;
			Window* WndC;
			Renderer* Rendr;
			int nCmdShow;
			wstring _t;
			int _w;
			int _h;
	};

}