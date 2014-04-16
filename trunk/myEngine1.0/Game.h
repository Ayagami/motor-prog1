#pragma once
#include "myEngine_API.h"
namespace DoMaRe{
	class Renderer;
	class MYENGINE_API Game{
		public:
			//Game();
			virtual bool Init(DoMaRe::Renderer&) = 0;
			virtual void Frame(DoMaRe::Renderer&) = 0;
			virtual void DeInit() = 0;
	};
}