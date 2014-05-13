#include "EMath.h"
#include "RenderTypes.h"
#include "Entity2D.h"
#include "myEngine_API.h"
namespace DoMaRe{
	class Renderer;
	//class Entity2D;
	class MYENGINE_API Quad : public Entity2D{
	public:	
		Quad();
		~Quad();
	public:
		/*void setPos(float fPosX,float fPosY);
		void setRotation(float fRotation);
		void setScale(float fScale);*/
		void setColor(DWORD c);
		void setColor(DWORD c, int v); /*
		float posX() const;
		float posY() const;
		float rotation() const;
		float scale() const;*/

	/*private:
		float _PosX, _PosY;
		float _Rot;
		float _Scale;
		Matrix _TrMatrix;
		void updateLocalTransformation();*/

	public:
		void draw(Renderer& r) const;
	private:
		ColorVertex* _Vertex;
	};
}