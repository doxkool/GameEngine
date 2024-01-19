#pragma once

#include "Core/Texture.h"

#include "Renderer/Camera.h"
#include "Renderer/Primitives.h"
#include "Renderer/VertexArray.h"

#include "Core/Logger.h"

#include <vector>
#include <string>

#include <GL/glew.h>

namespace Engine
{

	class Mesh
	{
		public:
			Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices, std::vector<Texture>& textures);
			//Mesh(Vertex* vertices, GLuint* indices, Texture* textures);

			// mesh data
			std::vector <Vertex> vertices;
			std::vector <GLuint> indices;
			std::vector <Texture> textures;

			void Draw
			(
				Shader& shader,
				Camera& camera,
				glm::mat4 matrix = glm::mat4(1.0f),
				glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f),
				glm::quat rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f),
				glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f)
			);

			VertexArray VAO;

		private:

			glm::vec3 position;
			glm::vec3 origin;
			glm::vec3 rotation;
			glm::vec3 scale;

			glm::mat4 ModelMatrix;
	};
}