#pragma once
#include "Game.h"
#include "RenderTypes.h"
namespace MiJuego{
	class Juego : public DoMaRe::Game{
	public:
		bool Init(DoMaRe::Renderer&);
		void Frame(DoMaRe::Renderer&);
		void DeInit();
	private:
		DoMaRe::ColorVertex v[4];
	};
}