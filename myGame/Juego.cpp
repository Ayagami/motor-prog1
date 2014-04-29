#include "Juego.h"
//#include "Renderer.h"

using namespace MiJuego;

bool Game::Init(DoMaRe::Renderer& r){
	m_kQuad1.setScale(100.0f);
	m_kQuad1.setPos(100.0f,100.0f);

	m_kQuad2.setScale(200.0f);
	m_kQuad2.setPos(-100.0f,-100.0f);
	m_kQuad2.setRotation(-45.0f);

	return true;
}
void Game::Frame(DoMaRe::Renderer& r){
	static float fRot = 0.0f;
	fRot+= 0.001f;
	m_kQuad1.setRotation(fRot);

	m_kQuad1.draw(r);
	m_kQuad2.draw(r);

}
void Game::DeInit(){
}
