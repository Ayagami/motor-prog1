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
		DoMaRe::Quad m_kQuad1;
		DoMaRe::Quad m_kQuad2;
	};
}