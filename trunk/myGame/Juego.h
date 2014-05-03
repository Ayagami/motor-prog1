#pragma once
#include "Game.h"
#include "Quad.h"
#include "RenderTypes.h"
#include "Renderer.h"
namespace MiJuego{
	class Game : public DoMaRe::Game{
	public:
		bool Init(DoMaRe::Renderer&);
		void Frame(DoMaRe::Renderer&);
		void DeInit();
	private:
		DoMaRe::Quad _Cubo1;
		DoMaRe::Quad _Cubo2;
	};
}