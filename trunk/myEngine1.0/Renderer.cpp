#pragma once
#include "Renderer.h"
using namespace DoMaRe;
Renderer::Renderer():
d3d(NULL),
d3d_dev(NULL),
p_vb(NULL)
{
	// Again, Nothing to do.
}

Renderer::~Renderer(){

	if(p_vb){
	delete p_vb;
	p_vb = NULL;
	}
	if(d3d_dev){
	d3d_dev->Release();
	d3d_dev = NULL;
	}

	if(d3d){
	d3d->Release();
	d3d = NULL;
	}

	
}

bool Renderer::Init(HWND _HwnD){
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = _HwnD;
	if(d3d->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _HwnD, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3d_dev) == D3D_OK){
		p_vb = new DoMaRe::VertexBuffer(d3d_dev, sizeof(DoMaRe::ColorVertex), DoMaRe::ColorVertexType);
		return true;
	}
	return false;
}

void Renderer::BeginFrame(){
	d3d_dev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,255), 1.0f, 0);
	d3d_dev->BeginScene();
}

void Renderer::EndFrame(){
	p_vb->flush();
	d3d_dev->EndScene();
	d3d_dev->Present(NULL,NULL,NULL,NULL);
}


D3DPRIMITIVETYPE primitiveMap[DoMaRe::PrimitiveCount] = {
        D3DPT_TRIANGLELIST, 
        D3DPT_TRIANGLESTRIP,
        D3DPT_POINTLIST,
        D3DPT_LINELIST,     
        D3DPT_LINESTRIP,
        D3DPT_TRIANGLEFAN
};

void Renderer::Draw(const void* v, DoMaRe::Primitive p, size_t vC){
	p_vb->bind();
	p_vb->draw(v,primitiveMap[p], vC);
}
