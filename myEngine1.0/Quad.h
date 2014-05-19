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
		void setColor(DWORD c);
		void setColor(DWORD c, int v);

	public:
		void draw(Renderer& r) const;
	private:
		ColorVertex* _Vertex;
	};
}