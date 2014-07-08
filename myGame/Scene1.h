#pragma once
#include "Scene\Scene.h"
#include "Entity2D\Quad.h"
#include "Entity2D\Sprite.h"
#include "Renderer\RenderTypes.h"
#include "Renderer\Renderer.h"
#include "Entity2D\animation.h"
#include "timer\pg1_timer.h"
#include "input\pg1_directinput.h"
#include "Scene\Import.h"
namespace MiJuego{
	class Scene1 : public DoMaRe::Scene{
	public:
		bool Init(DoMaRe::Renderer&, DoMaRe::Import&);
		void Frame(DoMaRe::Renderer&, DoMaRe::DirectInput&, DoMaRe::Timer&, DoMaRe::Import&);
		void DeInit();
	private:

		DoMaRe::Quad _Cubo1;

		DoMaRe::Sprite _Sprite2;
	};
}