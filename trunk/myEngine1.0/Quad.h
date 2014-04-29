#include "EMath.h"
#include "RenderTypes.h"

namespace DoMaRe{
	class Renderer;
	class MYENGINE_API Quad{
	public:	
		Quad();
		~Quad();
	public:
		void setPos(float fPosX,float fPosY);
		void setRotation(float fRotation);
		void setScale(float fScale);

		float posX() const;
		float posY() const;
		float rotation() const;
		float scale() const;

	private:
		float m_fPosX, m_fPosY;
		float m_fRotation;
		float m_fScale;

		Matrix m_pkTransformationMatrix;
		void updateLocalTransformation();

	public:
		void draw(Renderer& r) const;
	private:
		ColorVertex* m_pakVertices;
	};
}