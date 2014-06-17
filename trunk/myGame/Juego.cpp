#include "Juego.h"

using namespace MiJuego;

bool Game::Init(DoMaRe::Renderer& r){
	_Cubo1.setScale(100.0f,100.0f);
	_Cubo1.setPos(100.0f,100.0f);
	/*
	_Cubo2.setScale(200.0f,200.0f);
	_Cubo2.setPos(-100.0f,-100.0f);
	_Cubo2.setRotation(-45.0f);
	
	_Cubo1.setColor(DoMaRe_COLOR_RGB(200,55,250));

	for(int i = 0; i < 4; i++)
		_Cubo2.setColor(DoMaRe_COLOR_RGB(85 + (i * 15), 30 + (i * 30),23 + (i*10)), i);
		
	_Sprite1.setScale(100.0f,100.0f);
	_Sprite1.setPos(0.0f,0.0f);

	DoMaRe::Texture _mTexture = r.loadTexture("assets/Zelda.png", DoMaRe_COLOR_RGB(0,0,0));
	_Sprite1.setTexture(_mTexture);
	*/
	DoMaRe::Texture kCharactersTexture = r.loadTexture("assets/Link.png", DoMaRe_COLOR_RGB(0,255,0));
	_Sprite2.setTexture(kCharactersTexture);

	m_Sprite2_Idle.setLength(1500.0f);
	m_Sprite2_Idle.addFrame(512.0f,1024.0f, 94.0f, 20.0f, 23.0f, 41.0f);
	m_Sprite2_Idle.addFrame(512.0f,1024.0f, 94.0f, 20.0f, 23.0f, 41.0f);
	m_Sprite2_Idle.addFrame(512.0f,1024.0f, 94.0f, 20.0f, 23.0f, 41.0f);
	m_Sprite2_Idle.addFrame(512.0f,1024.0f, 94.0f, 20.0f, 23.0f, 41.0f);
	m_Sprite2_Idle.addFrame(512.0f,1024.0f, 94.0f, 20.0f, 23.0f, 41.0f);
	m_Sprite2_Idle.addFrame(512.0f,1024.0f, 94.0f, 20.0f, 23.0f, 41.0f);
	m_Sprite2_Idle.addFrame(512.0f,1024.0f, 94.0f, 20.0f, 23.0f, 41.0f);
	m_Sprite2_Idle.addFrame(512.0f,1024.0f, 94.0f, 20.0f, 23.0f, 41.0f);
	m_Sprite2_Idle.addFrame(512.0f,1024.0f, 94.0f, 20.0f, 23.0f, 41.0f);
	m_Sprite2_Idle.addFrame(512.0f,1024.0f, 94.0f, 20.0f, 23.0f, 41.0f);
	m_Sprite2_Idle.addFrame(512.0f,1024.0f, 144.0f, 20.0f, 23.0f, 41.0f);
	m_Sprite2_Idle.addFrame(512.0f,1024.0f, 194.0f, 20.0f, 23.0f, 41.0f);
	m_Sprite2_Idle.addFrame(512.0f,1024.0f, 144.0f, 20.0f, 23.0f, 41.0f);

	m_Sprite2_Walk.setLength(800.0f);
	m_Sprite2_Walk.addFrame(512.0f, 1024.0f, 40.0f, 122.0f, 32.0f, 37.0f);
	m_Sprite2_Walk.addFrame(512.0f, 1024.0f, 86.0f, 122.0f, 39.0f, 38.0f);
	m_Sprite2_Walk.addFrame(512.0f, 1024.0f, 136.0f, 122.0f, 39.0f, 38.0f);
	m_Sprite2_Walk.addFrame(512.0f, 1024.0f, 188.0f, 123.0f, 35.0f, 36.0f);
	m_Sprite2_Walk.addFrame(512.0f, 1024.0f, 241.0f, 123.0f, 29.0f, 35.0f);
	m_Sprite2_Walk.addFrame(512.0f, 1024.0f, 38.0f, 173.0f, 35.0f, 36.0f);
	m_Sprite2_Walk.addFrame(512.0f, 1024.0f, 87.0f, 172.0f, 37.0f, 37.0f);
	m_Sprite2_Walk.addFrame(512.0f, 1024.0f, 138.0f, 172.0f, 35.0f, 37.0f);
	m_Sprite2_Walk.addFrame(512.0f, 1024.0f, 188.0f, 173.0f, 35.0f, 36.0f);
	m_Sprite2_Walk.addFrame(512.0f, 1024.0f, 239.0f, 173.0f, 33.0f, 36.0f);

	_Sprite2.setScale(90.0f, 160.0f);
	_Sprite2.setPos(0.0f, 100.0f);
	_Sprite2.setAnimation(&m_Sprite2_Idle);


	
	return true;
}
void Game::Frame(DoMaRe::Renderer& r, DoMaRe::DirectInput& eInput, DoMaRe::Timer& t){
	static float fSp = 1.0f;

	/*if(eInput.keyDown(DoMaRe::Input::KEY_UP)){
		_Sprite1.setPos(_Sprite1.posX(), _Sprite1.posY() + fSp);
	}

	if(eInput.keyDown(DoMaRe::Input::KEY_DOWN)){
		_Sprite1.setPos(_Sprite1.posX(), _Sprite1.posY() - fSp);
	}*/

	if(eInput.keyDown(DoMaRe::Input::KEY_LEFT)){
		_Sprite2.setPos(_Sprite2.posX() - fSp, _Sprite2.posY());
		_Sprite2.setAnimation(&m_Sprite2_Walk);

		_Sprite2.setScale( -90.0f, 160.0f);
	}
	else if(eInput.keyDown(DoMaRe::Input::KEY_RIGHT)){
		_Sprite2.setPos(_Sprite2.posX() + fSp, _Sprite2.posY());
		_Sprite2.setAnimation(&m_Sprite2_Walk);

		_Sprite2.setScale( 90.0f, 160.0f);
	}else{
		_Sprite2.setAnimation(&m_Sprite2_Idle);
		_Sprite2.setScale(90.0f, 160.0f);
	}
	
/*	
	static float fRot = 0.0f;
	fRot+= 0.001f;
	_Cubo1.setRotation(fRot);

	
	_Cubo2.draw(r);
	
	_Sprite1.setRotation(fRot);
	_Sprite1.draw(r);
	*/
	_Cubo1.draw(r);
	_Sprite2.update(t);
	_Sprite2.draw(r);
}
void Game::DeInit(){
}
