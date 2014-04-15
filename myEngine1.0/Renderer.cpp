#pragma once
#include "Renderer.h"
#include <time.h>

Renderer::Renderer():
d3d(new LPDIRECT3D9()),
d3d_dev(new LPDIRECT3DDEVICE9())
{
	// Again, Nothing to do.
}

Renderer::~Renderer(){
	(*d3d_dev)->Release();
	delete d3d_dev;
	(*d3d)->Release();
	delete d3d;
}

bool Renderer::Init(HWND _HwnD){
	*d3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = _HwnD;
	if((*d3d)->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _HwnD, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, d3d_dev) != D3D_OK)
		return false;
	return true;
}

void Renderer::BeginFrame(){
	srand(time(NULL));
	(*d3d_dev)->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(((int) ( 1+rand()%(255-1) ) ),((int) ( 1+rand()%(255-1) )), ((int) ( 1+rand()%(255-1) )) ), 1.0f, 0);
	(*d3d_dev)->BeginScene();
}

void Renderer::EndFrame(){
	(*d3d_dev)->EndScene();
	(*d3d_dev)->Present(NULL,NULL,NULL,NULL);
}

LPDIRECT3D9 Renderer::Getd3d(){
	return *d3d;
}
LPDIRECT3DDEVICE9 Renderer::Getd3ddev(){
	return *d3d_dev;
}