#include "Juego.h"
#include "Renderer.h"

using namespace MiJuego;

bool Game::Init(DoMaRe::Renderer& r){
	static const float SIZE = 0.5f;
	v[0].x = -SIZE;	v[0].y = SIZE;	v[0].z = 0.0f;
	v[1].x = SIZE;	v[1].y = SIZE;	v[1].z = 0.0f;
	v[2].x = -SIZE;	v[2].y = -SIZE;	v[2].z = 0.0f;
	v[3].x = SIZE;	v[3].y = -SIZE;	v[3].z = 0.0f;

	v[0].color = DoMaRe_COLOR_RGB(255,0,0);
	v[1].color = DoMaRe_COLOR_RGB(0,255,0);
	v[2].color = DoMaRe_COLOR_RGB(0,255,0);
	v[3].color = DoMaRe_COLOR_RGB(255,0,0);

	return true;
}
void Game::Frame(DoMaRe::Renderer& r){
	r.Draw(v, DoMaRe::TriangleStrip, 4);
}
void Game::DeInit(){
}
