#pragma once
#include "Game.h"
#include "Quad.h"
#include "Sprite.h"
#include "RenderTypes.h"
#include "Renderer.h"
#include "animation.h"
#include "timer\pg1_timer.h"
#include "input\pg1_directinput.h"
namespace MiJuego{
	class Game : public DoMaRe::Game{
	public:
		bool Init(DoMaRe::Renderer&);
		void Frame(DoMaRe::Renderer&, DoMaRe::DirectInput&, DoMaRe::Timer&);
		void DeInit();
	private:

		DoMaRe::Quad _Cubo1;
		DoMaRe::Sprite _Sprite2;

		DoMaRe::Animation m_Sprite2_Idle;
		DoMaRe::Animation m_Sprite2_Walk;
		DoMaRe::Animation m_Sprite2_Jump;
	};
}