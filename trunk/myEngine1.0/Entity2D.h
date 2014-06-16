#pragma once
#include "EMath.h"
#include "RenderTypes.h"
namespace DoMaRe{
	class MYENGINE_API Entity2D{
	public:
		Entity2D();
		virtual ~Entity2D();
	public:
		void setPos(float fPosX,float fPosY);
		void setRotation(float fRotation);
		void setScale(float fScaleX, float fScaleY);
		float posX() const;
		float posY() const;
		float rotation() const;
		float scale() const;
		void updateLocalTransformation();
		const Matrix transformationMatrix();
	private:
		float _PosX, _PosY;
		float _Rot;
		float _ScaleX,_ScaleY;
	protected:
		Matrix _TrMatrix;
	};
}