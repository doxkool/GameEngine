#pragma once

#include "Core/Mesh.h"

namespace Engine
{
	class Model
	{
	public:
		// Initialize a model from premitive.
		//Model(const Primitive& primitive, const char* texturePath);
		// Initialize a model from a file.
		//Model(const char* filepath);

		Model();

		void LoadMesh(const Primitive& primitive, const char* texturePath);

		void Draw(Shader& shader, Camera& camera);

		// mesh data
		std::vector<Vertex> vertices;

	private:
		Primitive I_primitive;

		// All the meshes and transformations
		std::vector<Mesh> meshes;
		std::vector<Vertex> vertex;
		std::vector<GLuint> index;
		std::vector<glm::vec3> translationsMeshes;
		std::vector<glm::quat> rotationsMeshes;
		std::vector<glm::vec3> scalesMeshes;
		std::vector<glm::mat4> matricesMeshes;
	};
}