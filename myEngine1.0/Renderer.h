#pragma once
#include <Windows.h>
#include <d3d9.h>
class Renderer{
	public:
		Renderer();
		~Renderer();
		bool Init(HWND _HwnD);
		void BeginFrame();
		void EndFrame();
		LPDIRECT3D9 Getd3d();
		LPDIRECT3DDEVICE9 Getd3ddev();
	private:
		LPDIRECT3D9 * d3d;
		LPDIRECT3DDEVICE9 * d3d_dev;
};