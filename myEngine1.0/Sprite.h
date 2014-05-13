//#include "EMath.h"
#include "RenderTypes.h"
#include "myEngine_API.h"
#include "Entity2D.h"
namespace DoMaRe{
class Renderer;
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

	void draw(Renderer& r) const;
private:
	Texture s_Texture;
	TexCoordVertex* s_Vertex;
};
}