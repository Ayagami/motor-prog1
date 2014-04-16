#include "Juego.h"
#include "Renderer.h"

using namespace MiJuego;

bool Juego::Init(DoMaRe::Renderer& r){
	static const float SIZE = 0.5f;
	v[0].x = -SIZE;	v[0].y = SIZE;	v[0].z = 0.0f;
	v[1].x = SIZE;	v[1].y = SIZE;	v[1].z = 0.0f;
	v[2].x = -SIZE;	v[2].y = -SIZE;	v[2].z = 0.0f;
	v[3].x = SIZE;	v[3].y = -SIZE;	v[3].z = 0.0f;

	v[0].color = D3DCOLOR_XRGB(200,0,0);
	v[1].color = D3DCOLOR_XRGB(200,0,0);
	v[2].color = D3DCOLOR_XRGB(200,0,0);
	v[3].color = D3DCOLOR_XRGB(200,0,0);

	return true;
}
void Juego::Frame(DoMaRe::Renderer& r){
	r.Draw(v, DoMaRe::TriangleStrip, 4);
}
void Juego::DeInit(){
}
