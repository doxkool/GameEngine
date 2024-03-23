#pragma once

#include "Core/Base.h"

#include "Renderer/Buffers/ElementBuffer.h"

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>

namespace Engine
{
	struct Vertex {
		glm::vec3 position;
		glm::vec3 color;
		glm::vec2 texCoords;
		//glm::vec3 normals;
	};

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static Ref<VertexBuffer> Create(uint32_t size);
	};
}