#pragma once

#include "Core/Mesh.h"

#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/quaternion.hpp>

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

		void LoadMesh(const Primitive& primitive, glm::vec3 translation = glm::vec3(0.f), glm::vec3 rotation = glm::vec3(0.f), glm::vec3 scale = glm::vec3(1.f), const char* texturePath = "Engine/Default_Tex.jpg");

		void UpdateModelMatrices(glm::vec3 translation, glm::vec3 rotation, glm::vec3 scale);

		void Draw(Shader& shader, Camera& camera);


	private:
		Primitive I_primitive;

		// All the meshes and transformations
		std::vector<Mesh> meshes;
		std::vector<glm::vec3> translationsMeshes;
		std::vector<glm::quat> rotationsMeshes;
		std::vector<glm::vec3> scalesMeshes;
		std::vector<glm::mat4> matricesMeshes;
	};
}