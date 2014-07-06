//#include "EMath.h"
#include "../Renderer/RenderTypes.h"
#include "../myEngine_API.h"
#include "Entity2D.h"
namespace DoMaRe{
class Renderer;
class Animation;
class Timer;
class MYENGINE_API Sprite : public Entity2D{
public:
	Sprite();
	~Sprite();
public:
	void setTexture(Texture& _Texture);
	void setTextCoords( float U1, float V1,
						float U2, float V2,
						float U3, float V3,
						float U4, float V4
	);
	void setAnimation(Animation* pkAnimation);
	void update(Timer& rkTimer);
	void UpdateGravityPos();

	void draw(Renderer& r) const;
private:
	Texture s_Texture;
	TexCoordVertex* s_Vertex;
	
	Animation* m_pkAnimation;
	unsigned int m_uiPreviousFrame;
	
};
}