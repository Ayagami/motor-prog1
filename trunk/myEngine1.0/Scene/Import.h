#ifndef IMPORT_H
#define IMPORT_H

#include "../myEngine_API.h"
#include <string>
#include "../TinyXML/tinyxml2.h"
#include <list>
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
			static bool importScene(Scene&, std::string);
			static void importSprite(Scene&,tinyxml2::XMLElement*);
			static void importQuad(Scene&,tinyxml2::XMLElement*);
			static void importAnimation(std::list<Animation> &animations,tinyxml2::XMLElement*);
			//Renderer *renderer;
			
		public:
			void SetRenderer(Renderer * r ) { renderer = r;}
		private:
			Renderer * renderer;
	};
}


#endif
