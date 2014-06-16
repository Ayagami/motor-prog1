#pragma once
#include "Entity2D.h"
#include <d3dx9.h>
using namespace DoMaRe;
Entity2D::Entity2D() :
_PosX(0.0f),
_PosY(0.0f),
_Rot(0.0f),
_ScaleX(1.0f),
_ScaleY(1.0f),
_TrMatrix( new D3DXMATRIX() )
{

}
Entity2D::~Entity2D(){
	delete _TrMatrix;
	_TrMatrix = NULL;
}

void Entity2D::setPos(float fPosX, float fPosY){
	_PosX = fPosX;
	_PosY = fPosY;

	updateLocalTransformation();
}

void Entity2D::setRotation(float fRotation){
	_Rot = fRotation;
	updateLocalTransformation();
}

void Entity2D::setScale(float fScaleX, float fScaleY){
	_ScaleX = fScaleX;
	_ScaleY = fScaleY;
	updateLocalTransformation();
}

void Entity2D::updateLocalTransformation(){
 D3DXMATRIX translateMatrix;
 D3DXMatrixTranslation(&translateMatrix, _PosX, _PosY, 0);

 D3DXMATRIX rotationMatrix;
 D3DXMatrixRotationZ(&rotationMatrix, _Rot);

 D3DXMATRIX scaleMatrix;
 D3DXMatrixScaling(&scaleMatrix, _ScaleX, _ScaleY, 1);

 D3DXMatrixIdentity(_TrMatrix);
 D3DXMatrixMultiply(_TrMatrix,&translateMatrix,_TrMatrix);
 D3DXMatrixMultiply(_TrMatrix,&rotationMatrix,_TrMatrix);
 D3DXMatrixMultiply(_TrMatrix,&scaleMatrix,_TrMatrix);
}

const Matrix Entity2D::transformationMatrix(){
	return (_TrMatrix);
}

float Entity2D::posX() const{
	return _PosX;
}

float Entity2D::posY() const{
	return _PosY;
}