#pragma once

#include "Renderer/Primitives.h"

#include <vector>
#include <string>

#include <GL/glew.h>

namespace Engine
{

	class Mesh
	{
		public:
			Mesh(Primitive* primitive);

			// mesh data
			std::vector<Vertex> vertices;

			void initVAO();
			void updateModelMatrix();
			void render();

		private:

			//  render data
			unsigned int VAO, VBO, EBO;

			Vertex* vertexArray;
			unsigned nrOfVertices;
			GLuint* indexArray;
			unsigned nrOfIndices;

			glm::vec3 position;
			glm::vec3 origin;
			glm::vec3 rotation;
			glm::vec3 scale;

			glm::mat4 ModelMatrix;
	};
}