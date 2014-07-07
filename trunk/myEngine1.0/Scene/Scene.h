#pragma once
#include "..\myEngine_API.h"
#include <iostream>
#include <list>
#include <string>
namespace DoMaRe{
	class Entity2D;
	class Renderer;
	class MYENGINE_API Scene{
		public:
			Scene();
			bool Init();
			bool Frame(Renderer&);
			bool deinit();
			bool getEntity(Entity2D*, std::string);
			bool addEntity(Entity2D*);
		private:
			std::list<Entity2D*> m_pkEntidades;
	};
}