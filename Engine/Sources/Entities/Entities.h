#pragma once

#include "Entities/Components.h"

#include "Core/Logger.h"
#include "Core/Utilities.h"

#include <entt.hpp>
#include <vector>

namespace Engine
{
	class Entities
	{
	public:

		static void OnUpdate(TimeStep ts);

		static entt::entity& AddEntity(const std::string& name);

		static void AddComponent(entt::entity entity, ComponentType componentType);

		static void SetTextureComponent(entt::entity entity, std::string& TexturePath);
		static void SetMeshComponent(entt::entity entity, Vertex& vertex);
		static void SetShaderComponent(entt::entity entity, const char* vertexShaderFile, const char* fragmentShaderFile);

		static void RemoveComponent(const entt::entity entity);
		static void GetComponent(entt::entity entity);

		static void ClearAllEntity();

		static void Draw();

		const char* sceneName = "Scene";

	private:

		unsigned int sceneID = 0;

	};
}