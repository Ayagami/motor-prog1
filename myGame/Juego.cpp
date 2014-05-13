#include "Juego.h"
//#include "Renderer.h"

using namespace MiJuego;

bool Game::Init(DoMaRe::Renderer& r){
	_Cubo1.setScale(100.0f);
	_Cubo1.setPos(100.0f,100.0f);

	_Cubo2.setScale(200.0f);
	_Cubo2.setPos(-100.0f,-100.0f);
	_Cubo2.setRotation(-45.0f);
	
	_Cubo1.setColor(DoMaRe_COLOR_RGB(200,55,250));

	for(int i = 0; i < 4; i++)
		_Cubo2.setColor(DoMaRe_COLOR_RGB(85 + (i * 15), 30 + (i * 30),23 + (i*10)), i);
		
	_Sprite1.setScale(200.0f);
	_Sprite1.setPos(0.0f,0.0f);

	DoMaRe::Texture _mTexture = r.loadTexture("assets/text.jpg");
	_Sprite1.setTexture(_mTexture);
	//_Sprite1.setTextCoords(1,1,529,1,1,529,529,529);
	return true;
}
void Game::Frame(DoMaRe::Renderer& r){
	static float fRot = 0.0f;
	fRot+= 0.001f;
	_Cubo1.setRotation(fRot);

	_Cubo1.draw(r);
	_Cubo2.draw(r);
	
	_Sprite1.setRotation(fRot);
	_Sprite1.draw(r);
}
void Game::DeInit(){
}
