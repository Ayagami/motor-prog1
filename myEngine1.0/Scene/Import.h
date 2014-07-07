#pragma once
#include "../myEngine_API.h"
#include "../TinyXML/tinyxml2.h"
#include <string>
#include <list>
using namespace tinyxml2;
namespace DoMaRe{
	class Scene;
	class Quad;
	class Sprite;
	class Entity2D;
	class Animation;
	class Renderer;
	class MYENGINE_API Importer{
		static void importScene(Scene*, std::string);
		static void ImportSprite(Scene*, XMLElement*);
		static void ImportQuad(Scene*, XMLElement*);
		static void ImportAnimation(Sprite*, XMLElement*);
	private:
		static Renderer* renderer;
	};
}
