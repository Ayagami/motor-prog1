#pragma once
#include "../Renderer/EMath.h"
#include "../Renderer/RenderTypes.h"
namespace DoMaRe{
	class Renderer;
	class MYENGINE_API Entity2D{
	public:
		Entity2D();
		virtual ~Entity2D();
	public:
		void setPos(float fPosX,float fPosY);
		void setRotation(float fRotation);
		void setScale(float fScaleX, float fScaleY);

		void UseGravity(bool _T);
		void SetGravity(float _G);
		float posX() const;
		float posY() const;
		float rotation() const;
		float scale() const;
		float scaleX() const;
		float scaleY() const;
		float previousPosX() const;
		float previousPosY() const;
		float getGravity() const;
		bool isUsingGravity() const;

		enum CollisionResult{
			CollisionVertical,
			CollisionHorizontal,
			NoCollision
		};

		CollisionResult checkCollision(Entity2D& rkEntity2D) const;
		void drawAABB (Renderer& rkRenderer) const;

		void updateLocalTransformation();
		void returnToPos(float fPosX, float fPosY);
		const Matrix transformationMatrix();
	private:
		float _PosX, _PosY;
		float _Rot;
		float _ScaleX,_ScaleY;
		float _PreviousPosX, _PreviousPosY;
		float _Gravity;
		bool _UseGravity;
	protected:
		Matrix _TrMatrix;
	};
}