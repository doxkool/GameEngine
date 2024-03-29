#pragma once

#include "OpenGL/OpenGL.h"

namespace Engine
{
	class  OpenGLVertexBuffer
	{
	public:
		OpenGLVertexBuffer(uint32_t size);
		OpenGLVertexBuffer(std::vector<glm::vec3>& vertices);
		OpenGLVertexBuffer(float* vertices);
		~OpenGLVertexBuffer();

		void Bind();
		void Unbind();

		void SetData(const void* data, uint32_t size);

		static Ref<OpenGLVertexBuffer> Create(uint32_t size);
		static Ref<OpenGLVertexBuffer> Create(std::vector<glm::vec3>& vertices);
		static Ref<OpenGLVertexBuffer> Create(float* vertices);

	private:
		uint32_t ID;
	};
}