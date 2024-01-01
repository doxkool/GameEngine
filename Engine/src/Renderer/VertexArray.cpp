#include "Renderer/VertexArray.h"

#include "Platforms/OpenGL/OpenGL_VertexArray.h"



namespace Engine {

	Ref<VertexArray> VertexArray::Create()
	{
		return CreateRef<OpenGL_VertexArray>();
	}

}