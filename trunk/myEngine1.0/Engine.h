#pragma once
#include <iostream>
#include "myEngine_API.h"
class Window;
class Renderer;
#include <Windows.h>
using namespace std;
	class MYENGINE_API Engine{

		public:
			Engine(HINSTANCE hInst ,int nCmdS, string t, int w, int h);
			~Engine();
			bool init();
			void run();
			HWND hWnd;

		private:
			HINSTANCE hInstance;
			Window* WndC;
			Renderer* Rendr;
			int nCmdShow;
			string _t;
			int _w;
			int _h;
	};