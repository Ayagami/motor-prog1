#include "Scene.h"
#include "..\Entity2D\Entity2D.h"
using namespace DoMaRe;

Scene::Scene()/* : m_pkEntidades(new std::list<Entity2D*>)*/{

}

bool Scene::Init(){
	return true;
	// Aca van cosas del importer.
}

bool Scene::Frame(DoMaRe::Renderer& r){
	if(!m_pkEntidades.empty()){
		std::list<Entity2D*>::iterator it;
		for(it = m_pkEntidades.begin(); it != m_pkEntidades.end(); it++){
			(*it)->draw(r);
		}
		return true;
	}
	return false;
}

bool Scene::deinit(){
	//
	return true;
}

bool Scene::addEntity(Entity2D* Entity){
	m_pkEntidades.push_back(Entity);
	return true;
}

bool Scene::getEntity(Entity2D* Entity, std::string Name){

		if(!m_pkEntidades.empty()){
		std::list<Entity2D*>::iterator it;
		for(it = m_pkEntidades.begin(); it != m_pkEntidades.end(); it++){
			if(Name == (*it)->getName())
				Entity = *it;
		}
		return true;
		}

	return false;
}