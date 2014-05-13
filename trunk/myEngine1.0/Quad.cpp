#include "Quad.h"
#include "Entity2D.h"
#include "Renderer.h"
#include <d3dx9.h>
using namespace DoMaRe;

Quad::Quad():
/*_PosX(0.0f),
_PosY(0.0f),
_Rot(0.0f),
_Scale(1.0f),
_TrMatrix( new D3DXMATRIX() ),*/
Entity2D(),
_Vertex( new ColorVertex[4]){

_Vertex[0].x = -0.5f; _Vertex[0].y = 0.5f; _Vertex[0].z = 0.0f;
_Vertex[1].x = 0.5f; _Vertex[1].y = 0.5f; _Vertex[1].z = 0.0f;
_Vertex[2].x = -0.5f; _Vertex[2].y = -0.5f; _Vertex[2].z = 0.0f;
_Vertex[3].x = 0.5f; _Vertex[3].y = -0.5f; _Vertex[3].z = 0.0f;


// Setting the default Color (255,0,0)
_Vertex[0].color = DoMaRe_COLOR_RGB(255,0,0);
_Vertex[1].color = DoMaRe_COLOR_RGB(255,0,0);
_Vertex[2].color = DoMaRe_COLOR_RGB(255,0,0);
_Vertex[3].color = DoMaRe_COLOR_RGB(255,0,0);

updateLocalTransformation();
}

Quad::~Quad(){
	delete[] _Vertex;
	_Vertex = NULL;
}

/*void Quad::setPos(float fPosX, float fPosY){
	_PosX = fPosX;
	_PosY = fPosY;

	updateLocalTransformation();
}*/

void Quad::setColor(DWORD c){
	for(int i = 0; i < 4; i++)
		_Vertex[i].color = c;
}

void Quad::setColor(DWORD c, int v){
	if(v >= 0 && v < 4)
		_Vertex[v].color = c;
}

/*void Quad::setRotation(float fRotation){
	_Rot = fRotation;
	updateLocalTransformation();
}*/

/*void Quad::setScale(float fScale){
	_Scale = fScale;
	updateLocalTransformation();
}*/

void Quad::draw(Renderer& r) const{
	r.setCurrentTexture(NoTexture);
	r.setMatrix(World, _TrMatrix );
	r.Draw(_Vertex, DoMaRe::TriangleStrip, 4);
}

/*void Quad::updateLocalTransformation(){
 D3DXMATRIX translateMatrix;
 D3DXMatrixTranslation(&translateMatrix, _PosX, _PosY, 0);

 D3DXMATRIX rotationMatrix;
 D3DXMatrixRotationZ(&rotationMatrix, _Rot);

 D3DXMATRIX scaleMatrix;
 D3DXMatrixScaling(&scaleMatrix, _Scale, _Scale, 1);

 D3DXMatrixIdentity(_TrMatrix);
 D3DXMatrixMultiply(_TrMatrix,&translateMatrix,_TrMatrix);
 D3DXMatrixMultiply(_TrMatrix,&rotationMatrix,_TrMatrix);
 D3DXMatrixMultiply(_TrMatrix,&scaleMatrix,_TrMatrix);

}*/