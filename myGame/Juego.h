#pragma once
#include "Game.h"
#include "Quad.h"
#include "Sprite.h"
#include "RenderTypes.h"
#include "Renderer.h"
#include "animation.h"
#include "input\pg1_directinput.h"
namespace MiJuego{
	class Game : public DoMaRe::Game{
	public:
		bool Init(DoMaRe::Renderer&);
		void Frame(DoMaRe::Renderer&, DoMaRe::DirectInput&);
		void DeInit();
	private:
		DoMaRe::Quad _Cubo1;
		DoMaRe::Quad _Cubo2;
		DoMaRe::Sprite _Sprite1;

		DoMaRe::Sprite _Sprite2;

		DoMaRe::Animation m_Sprite2_Idle;
		DoMaRe::Animation m_Sprite2_Walk;
	};
}