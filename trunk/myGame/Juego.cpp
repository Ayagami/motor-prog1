#include "Juego.h"
bool d = true;
using namespace MiJuego;

bool Game::Init(DoMaRe::Renderer& r, DoMaRe::Import& Importer){
	Escena1 = new Scene1();
	_currentScene = Escena1;
	Importer.importScene(*Escena1, "Archivo.xml");
	/*
	Importer.importScene
	_Cubo1.setScale(1000.0f,30.0f);
	_Cubo1.setPos(0,-300);

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
	
	_Sprite2.UseGravity(true);
	_Sprite2.SetGravity(0.1f);
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

	m_Sprite2_Jump.setLength(1000.0f);
//	m_Sprite2_Jump.addFrame(512.0f, 1024.0f, 239.0f, 22.0f, 34.0f, 38.0f);
//	m_Sprite2_Jump.addFrame(512.0f, 1024.0f, 291.0f, 27.0f, 30.0f, 28.0f);
	m_Sprite2_Jump.addFrame(512.0f, 1024.0f, 342.0f, 18.0f, 28.0f, 45.0f);
	m_Sprite2_Jump.addFrame(512.0f, 1024.0f, 387.0f, 19.0f, 38.0f, 43.0f);
	m_Sprite2_Jump.addFrame(512.0f, 1024.0f, 440.0f, 9.0f, 31.0f, 54.0f);
	m_Sprite2_Jump.addFrame(512.0f, 1024.0f, 440.0f, 9.0f, 31.0f, 54.0f);
	m_Sprite2_Jump.addFrame(512.0f, 1024.0f, 440.0f, 9.0f, 31.0f, 54.0f);
	m_Sprite2_Jump.addFrame(512.0f, 1024.0f, 440.0f, 9.0f, 31.0f, 54.0f);
	m_Sprite2_Jump.addFrame(512.0f, 1024.0f, 440.0f, 9.0f, 31.0f, 54.0f);

	_Sprite2.setScale(60.0f, 160.0f);
	_Sprite2.setPos(0.0f, 100.0f);
	_Sprite2.setAnimation(&m_Sprite2_Idle);


	*/
	return true;
}
void Game::Frame(DoMaRe::Renderer& r, DoMaRe::DirectInput& eInput, DoMaRe::Timer& t, DoMaRe::Import& Importer){
	/*// Cubo Rebote

	static float fSp = 3.0f;
	static float initGravity = _Sprite2.getGravity();
	static float jumpSpeed = 7;
	static bool isJumping = false;

	if(_Sprite2.checkCollision(_Cubo1) == DoMaRe::Entity2D::CollisionHorizontal ){
		isJumping = true;
		//_Sprite2.setAnimation(&m_Sprite2_Jump);
		//_Sprite2.setAnimation(&m_Sprite2_Idle);

		_Sprite2.UseGravity(true);
		_Sprite2.SetGravity( _Sprite2.getGravity()  +  fSp / 10 /*  / t.fps() / 100*/  /* );				
		_Sprite2.returnToPos( _Sprite2.previousPosX(), _Sprite2.posY() );
	}else if(_Sprite2.checkCollision(_Cubo1) == DoMaRe::Entity2D::CollisionVertical){
		isJumping = false;
		//_Sprite2.setAnimation(&m_Sprite2_Jump);
		_Sprite2.UseGravity(false);
		_Sprite2.SetGravity(initGravity);
		_Sprite2.returnToPos( _Sprite2.posX() , _Sprite2.previousPosY() );
	}else{
		isJumping = true;
		//_Sprite2.setAnimation(&m_Sprite2_Jump);
		_Sprite2.UseGravity(true);
		_Sprite2.SetGravity( _Sprite2.getGravity()  +  fSp / 10 /*  / t.fps() / 100*/ /*);
	}

	if(eInput.keyDown(DoMaRe::Input::KEY_LEFT)){

		if(eInput.keyDown(DoMaRe::Input::KEY_UP) && isJumping == false){
		_Sprite2.setAnimation(&m_Sprite2_Jump);
		_Sprite2.setPos(_Sprite2.posX(), _Sprite2.posY() + 0.5f);
		_Sprite2.SetGravity(-jumpSpeed);
		_Sprite2.UseGravity(true);
		isJumping = true;
		}

		_Sprite2.setPos(_Sprite2.posX() - fSp, _Sprite2.posY());
		if(!isJumping) _Sprite2.setAnimation(&m_Sprite2_Walk);
		d=false;
		if(!isJumping) _Sprite2.setScale( -90.0f, 160.0f);
	}
	else if(eInput.keyDown(DoMaRe::Input::KEY_RIGHT)){

		if(eInput.keyDown(DoMaRe::Input::KEY_UP) && isJumping == false){
		_Sprite2.setAnimation(&m_Sprite2_Jump);
		_Sprite2.setPos(_Sprite2.posX(), _Sprite2.posY() + 0.5f);
		_Sprite2.SetGravity(-jumpSpeed);
		_Sprite2.UseGravity(true);
		isJumping = true;
		}
		_Sprite2.setPos(_Sprite2.posX() + fSp, _Sprite2.posY());
		if(!isJumping) _Sprite2.setAnimation(&m_Sprite2_Walk);
		d=true;
		if(!isJumping)_Sprite2.setScale( 90.0f, 160.0f);
	}else if(eInput.keyDown(DoMaRe::Input::KEY_UP) && isJumping == false){
		_Sprite2.setPos(_Sprite2.posX(), _Sprite2.posY() + 0.5f);
		_Sprite2.setAnimation(&m_Sprite2_Jump);
		_Sprite2.SetGravity(-jumpSpeed);
		_Sprite2.UseGravity(true);
	}else{
		if(!isJumping)_Sprite2.setAnimation(&m_Sprite2_Idle);
		//if(!isJumping)_Sprite2.setAnimation(&m_Sprite2_Jump);
		if(d)
		_Sprite2.setScale(60.0f, 160.0f);
		else
		_Sprite2.setScale(-60.0f, 160.0f);
	}


	
	_Cubo1.draw(r);
	_Sprite2.UpdateGravityPos();
	_Sprite2.Update(t);
	_Sprite2.draw(r);
	_Sprite2.drawAABB(r);
	_Cubo1.drawAABB(r);*/
}
void Game::DeInit(){
}
