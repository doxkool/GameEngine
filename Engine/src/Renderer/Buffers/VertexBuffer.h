#pragma once

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
		VertexBuffer(std::vector<Vertex>& vertices);

		// Binds the VBO
		void Bind();
		// Unbinds the VBO
		void Unbind();
		// Deletes the VBO
		void Delete();

		// ID reference for the Vertex Array Object
		GLuint ID;

	private:

	};
}