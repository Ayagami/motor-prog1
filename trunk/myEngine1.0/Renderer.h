#pragma once
#include <Windows.h>
#include "VertexBuffer.h"
#include "myEngine_API.h"
#include "RenderTypes.h"
#include "EMath.h"
#include <d3d9.h>
namespace DoMaRe{
class MYENGINE_API Renderer{
	public:
		Renderer();
		~Renderer();
		bool Init(HWND _HwnD);
		void BeginFrame();
		void EndFrame();
		void setMatrix(MatrixType, const Matrix&);
		void Draw(ColorVertex*, DoMaRe::Primitive, size_t);
	private:
		IDirect3D9  * d3d;
		IDirect3DDevice9  * d3d_dev;
		DoMaRe::VertexBuffer * p_vb;
};
}