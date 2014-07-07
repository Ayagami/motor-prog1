#include "Game.h"
#include "Scene\Scene.h"
#include "Scene\Import.h"
using namespace DoMaRe;
Game::Game() : _currentScene(new Scene), GameOn(true){
}

Game::Game(std::string name) :  _currentScene(new Scene), GameOn(true){
	setScene(name);
}

Scene Game::currentScene(){
	return *_currentScene;
}

void Game::setScene(std::string name){
	// Import scene.
	Import::importScene(*_currentScene,name);
}