#include "Entities/Entities.h"

namespace Engine
{
	entt::registry m_Registry;

	void Entities::OnUpdate(TimeStep ts)
	{
		auto group = m_Registry.group<TransformComponent>(entt::get<Sprite2DComponent>);
		for (auto entity : group)
		{
			auto& [transform, sprite] = group.get<TransformComponent, Sprite2DComponent>(entity);

			Renderer2D::DrawQuad(transform.Transform);
		}
	}

	entt::entity& Entities::AddEntity(const std::string& name)
	{
		entt::entity entity = m_Registry.create();

		m_Registry.emplace<IDComponent>(entity);
		m_Registry.emplace<TransformComponent>(entity);

		if (name.empty())
		{
			m_Registry.emplace<TagComponent>(entity, "Entity");

			auto& tag = m_Registry.get<TagComponent>(entity);

			LOG_DEBUG("New entity created: {}", tag.Tag);
		}
		else {
			m_Registry.emplace<TagComponent>(entity, name);

			auto& tag = m_Registry.get<TagComponent>(entity);

			LOG_DEBUG("New entity created: {}", tag.Tag);
		}

		return entity;
	}

	void Entities::AddComponent(entt::entity entity, ComponentType componentType)
	{
		switch (componentType)
		{
		case transformComponent:

			if (m_Registry.any_of<TransformComponent>(entity))
			{
				LOG_ERROR("The entity '{}' already have a Transform component!", m_Registry.get<TagComponent>(entity).Tag);
				break;
			}

			m_Registry.emplace<TransformComponent>(entity, glm::mat4(1.0f));
			LOG_DEBUG("Transform component added to '{}'", m_Registry.get<TagComponent>(entity).Tag);

			break;
		case sprite2DComponent:

			if (m_Registry.any_of<Sprite2DComponent>(entity))
			{
				LOG_ERROR("The entity '{}' already have a Sprite2D component!", m_Registry.get<TagComponent>(entity).Tag);
				break;
			}

			m_Registry.emplace<Sprite2DComponent>(entity, glm::vec4(0.f, 1.0f, 0.f, 1.0f));

			LOG_DEBUG("Sprite2D component added to : '{}'", m_Registry.get<TagComponent>(entity).Tag);
			break;
		case textureComponent:

			if (m_Registry.any_of<TextureComponent>(entity))
			{
				LOG_ERROR("The entity '{}' already have a Texture component!", m_Registry.get<TagComponent>(entity).Tag);
				break;
			}

			m_Registry.emplace<TextureComponent>(entity, std::string(""));

			LOG_DEBUG("Texture component added to : '{}'", m_Registry.get<TagComponent>(entity).Tag);
			break;
		case shaderComponent:

			if (m_Registry.any_of<ShaderComponent>(entity))
			{
				LOG_ERROR("The entity '{}' already have a Shader component!", m_Registry.get<TagComponent>(entity).Tag);
				break;
			}

			m_Registry.emplace<ShaderComponent>(entity);

			LOG_DEBUG("Shader component added to : '{}'", m_Registry.get<TagComponent>(entity).Tag);
			break;
		default:
			LOG_ERROR("The component type ({}) was not added to {}..", componentType, m_Registry.get<TagComponent>(entity).Tag);
			break;
		}
	}

	void Entities::SetTextureComponent(entt::entity entity, std::string& TexturePath)
	{
		auto& TexComponent = m_Registry.get<TextureComponent>(entity);

		LOG_DEBUG("Texture component added to : '{}'");
	}

	void Entities::SetShaderComponent(entt::entity entity, const char* vertexShaderFile, const char* fragmentShaderFile)
	{
		m_Registry.emplace<ShaderComponent>(entity, vertexShaderFile, fragmentShaderFile);

		auto& test = m_Registry.get<TagComponent>(entity);
		LOG_DEBUG("Shader component added to : '{}'");
	}

	void Entities::RemoveComponent(entt::entity entity)
	{
		m_Registry.remove<TransformComponent>(entity);
	}

	void Entities::GetComponent(entt::entity entity)
	{
		m_Registry.get<TransformComponent>(entity);
	}

	void Entities::ClearAllEntity()
	{
		m_Registry.clear();
	}

	void Entities::Draw()
	{

	}
}