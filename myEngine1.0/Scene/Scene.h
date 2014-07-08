#pragma once
#include "..\myEngine_API.h"
#include <iostream>
#include <vector>
#include <string>
namespace DoMaRe{
	class Entity2D;
	class Sprite;
	class Quad;
	class Renderer;
	class Timer;
	class MYENGINE_API Scene{
		public:
			Scene();
			bool Init();
			bool Frame(Renderer&, Timer&);
			bool deinit();
			bool getEntity(Sprite**, std::string);
			bool getEntity(Quad**, std::string);
			bool addEntity(Entity2D*);
		private:
			std::vector<Entity2D*> m_pkEntidades;
	};
}