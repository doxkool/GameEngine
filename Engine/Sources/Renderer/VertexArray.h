#pragma once

#include "Core/Base.h"

#include "OpenGL/OpenGL.h"

namespace Engine
{
	class VertexArray
	{
		public:
			virtual ~VertexArray() = default;

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual void LinkAttribF(GLuint layout, GLuint numComponents, GLsizei stride, void* offset) = 0;

			static Ref<VertexArray> Create();
	};
}