#include "Quad.h"
#include "Renderer.h"
#include <d3dx9.h>
using namespace DoMaRe;

Quad::Quad():
m_fPosX(0.0f),
m_fPosY(0.0f),
m_fRotation(0.0f),
m_fScale(1.0f),
m_pkTransformationMatrix( new D3DXMATRIX() ),
m_pakVertices( new ColorVertex[4]){

m_pakVertices[0].x = -0.5; m_pakVertices[0].y = 0.5; m_pakVertices[0].z = 0;
m_pakVertices[1].x = -0.5; m_pakVertices[1].y = 0.5; m_pakVertices[1].z = 0;
m_pakVertices[2].x = -0.5; m_pakVertices[2].y = 0.5; m_pakVertices[2].z = 0;
m_pakVertices[3].x = -0.5; m_pakVertices[3].y = 0.5; m_pakVertices[3].z = 0;

m_pakVertices[0].color = DoMaRe_COLOR_RGB(255,0,0);
m_pakVertices[1].color = DoMaRe_COLOR_RGB(255,0,0);
m_pakVertices[2].color = DoMaRe_COLOR_RGB(255,0,0);
m_pakVertices[3].color = DoMaRe_COLOR_RGB(255,0,0);

updateLocalTransformation();
}

Quad::~Quad(){
	delete m_pkTransformationMatrix;
	m_pkTransformationMatrix = NULL;

	delete[] m_pakVertices;
	m_pakVertices = NULL;
}

void Quad::setPos(float fPosX, float fPosY){
	m_fPosX = fPosX;
	m_fPosY = fPosY;

	updateLocalTransformation();
}

void Quad::setRotation(float fRotation){
	m_fRotation = fRotation;
	updateLocalTransformation();
}

void Quad::setScale(float fScale){
	m_fScale = fScale;
	updateLocalTransformation();
}

void Quad::draw(Renderer& r) const{
	r.setMatrix(World, m_pkTransformationMatrix);
	r.Draw(m_pakVertices, DoMaRe::TriangleStrip, 4);
}

void Quad::updateLocalTransformation(){
 D3DXMATRIX translateMatrix;
 D3DXMatrixTranslation(&translateMatrix, m_fPosX, m_fPosY, 0);

 D3DXMATRIX rotationMatrix;
 D3DXMatrixRotationZ(&rotationMatrix, m_fRotation);

 D3DXMATRIX scaleMatrix;
 D3DXMatrixScaling(&scaleMatrix, m_fScale, m_fScale, 1);

 D3DXMatrixIdentity(m_pkTransformationMatrix);
 D3DXMatrixMultiply(m_pkTransformationMatrix,&translateMatrix,m_pkTransformationMatrix);
 D3DXMatrixMultiply(m_pkTransformationMatrix,&rotationMatrix,m_pkTransformationMatrix);
 D3DXMatrixMultiply(m_pkTransformationMatrix,&scaleMatrix,m_pkTransformationMatrix);

}