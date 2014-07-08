#ifndef IMPORT_H
#define IMPORT_H

#include "../myEngine_API.h"
#include <string>
#include "../TinyXML/tinyxml2.h"
#include <list>
#include <vector>

namespace DoMaRe
{
	
	class Scene;
	class Quad;
	class Sprite;
	class Animation;
	class Renderer;

	class MYENGINE_API Import
	{
		public:
			Import(Renderer& pkrenderer);
			bool importScene(Scene&, std::string);
			void importSprite(Scene&,tinyxml2::XMLElement*);
			void importQuad(Scene&,tinyxml2::XMLElement*);
			void importAnimation(std::vector<Animation> **animations,tinyxml2::XMLElement*);
			
			//Renderer *renderer;
		private:
			Renderer* _renderer;
	};
}


#endif