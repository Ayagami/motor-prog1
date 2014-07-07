#include "Import.h"
#include "Scene.h"
#include <list>
#include "../Entity2D/Quad.h"
#include "../Entity2D/Sprite.h"
#include "../Entity2D/Animation.h"
#include "../Entity2D/Entity2D.h"
#include "../Renderer/Renderer.h"
#include "../TinyXML/tinyxml2.h"
using namespace DoMaRe;

void Importer::ImportAnimation(Sprite* sp, XMLElement* animations){
while(animations != NULL)
	{
		//CREATE ANIMATION AUX
		Animation* anim_aux = new Animation();
		std::string name = animations->Attribute("name");
		float lenght = animations->FloatAttribute("lenght");
		float widthA = animations->FloatAttribute("width");
		float heightA = animations->FloatAttribute("height");
		anim_aux->setLength(lenght);
		tinyxml2::XMLElement *frame = animations->FirstChildElement("FRAME");
		while(frame != NULL)
		{
			
			float posX = frame->FloatAttribute("posX");
			float posY = frame->FloatAttribute("posY");
			float width = frame->FloatAttribute("width");
			float height = frame->FloatAttribute("height");

			anim_aux->addFrame(widthA,heightA,posX,posY,width,height);
			//ADDFRAME (posX, posY, width, height);
			frame = frame->NextSiblingElement("FRAME");
		}
	
		//anim_list.push_back(anim_aux);
		sp->AddAnimation(anim_aux);
		// PUSH_BACK ANIMATION
		animations = animations->NextSiblingElement("ANIMATION");
	}
}

void Importer::ImportSprite(Scene* scene, tinyxml2::XMLElement* root){
	tinyxml2::XMLElement *sprite = root->FirstChildElement("SPRITE");
	tinyxml2::XMLElement *instance = root->FirstChildElement("INSTANCE");

	while(sprite!= NULL)
	{	
		//CREAR SPRITE 
		Sprite* ent_sprite = new Sprite();
		std::string nameSprite = sprite->Attribute("name");
		std::string texture = sprite->Attribute("texture");
		int r = sprite->IntAttribute("r");
		int g = sprite->IntAttribute("g");
		int b = sprite->IntAttribute("b");
		DoMaRe::Texture _Texture = renderer->loadTexture(texture,DoMaRe_COLOR_RGB(r,g,b));

		//DoMaRe::Texture _mTexture = r.loadTexture("assets/Zelda.png", DoMaRe_COLOR_RGB(0,0,0));
		//CREAR LISTA ANIM
		//std::list<Animation*> anim_list;

		ImportAnimation(ent_sprite, sprite->FirstChildElement("ANIMATION"));
		instance = root->FirstChildElement("INSTANCE");
		while(instance != NULL)
		{
			if(instance->Attribute("sprite") == nameSprite)
			{
				std::string name = instance->Attribute("name");
				float posX = instance->FloatAttribute("posX");
				float posY = instance->FloatAttribute("posY");
				float rotation = instance->FloatAttribute("rotation");
				float scaleX = instance->FloatAttribute("scaleX");
				float scaleY = instance->FloatAttribute("scaleY");

				ent_sprite->setName(name);
				ent_sprite->setPos(posX,posY);
				ent_sprite->setRotation(rotation);
				ent_sprite->setScale(scaleX,scaleY);
				ent_sprite->setTexture(_Texture);
			}
			instance = instance->NextSiblingElement("INSTANCE");
		}

		//PUSH_BACK A LISTA ENTITY2D
		scene->addEntity(ent_sprite);
		sprite = sprite->NextSiblingElement("SPRITE");
	}
}

void Importer::ImportQuad(Scene* scene, XMLElement* root){
	tinyxml2::XMLElement *quad = root->FirstChildElement("QUAD");
	while(quad != NULL)
	{
		Quad* aux_quad = new Quad();
		std::string name = quad->Attribute("name");
		float posX = quad->FloatAttribute("posX");
		float posY = quad->FloatAttribute("posY");
		float rotation = quad->FloatAttribute("rotation");
		float scaleX = quad->FloatAttribute("scaleX");
		float scaleY = quad->FloatAttribute("scaleY");
		int r = quad->IntAttribute("r");
		int g = quad->IntAttribute("g");
		int b = quad->IntAttribute("b");

		aux_quad->setName(name);
		aux_quad->setPos(posX,posY);
		aux_quad->setRotation(rotation);
		aux_quad->setScale(scaleX,scaleY);
		aux_quad->setColor(DoMaRe_COLOR_RGB(r,g,b));

		scene->addEntity(aux_quad);

		quad = quad->NextSiblingElement("QUAD");
	}
}


void Importer::importScene(Scene* scene, std::string fName){
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile("../scene.xml");

	tinyxml2::XMLElement * root = xmlDoc.FirstChildElement("SCENE");
	ImportSprite(scene,root);
	ImportQuad(scene,root);
}