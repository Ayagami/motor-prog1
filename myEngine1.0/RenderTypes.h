#pragma once
#include <Windows.h>
#include "myEngine_API.h"

namespace DoMaRe{
	struct MYENGINE_API ColorVertex{
		float x,y,z;
		DWORD color;
	};

	extern const int ColorVertexType;

	enum Primitive{
		TriangleList = 0,
        TriangleStrip,
        PointList,
        LineList,
        LineStrip,
        TriangleFan,
        PrimitiveCount
	};
#define DoMaRe_COLOR_ARGB(a,r,g,b)  ((DWORD)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))
#define DoMaRe_COLOR_RGB(r,g,b) DoMaRe_COLOR_ARGB(0xff,r,g,b)
}