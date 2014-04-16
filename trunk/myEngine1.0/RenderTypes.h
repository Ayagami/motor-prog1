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
}