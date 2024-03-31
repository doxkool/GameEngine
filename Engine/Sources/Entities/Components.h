#pragma once

#include "Core/Base.h"

#include "Renderer/Renderer2D.h"
#include "OpenGL/OpenGLTexture.h"
#include "OpenGL/OpenGLShader.h"

#include <glm.hpp>

namespace Engine
{
	enum ComponentType
	{
		transformComponent,
		sprite2DComponent,
		textureComponent,
		shaderComponent
	};

	struct IDComponent
	{
		int ID;

		IDComponent() = default;
		IDComponent(const IDComponent&) = default;
	};

	struct TagComponent
	{
		std::string Tag;

		TagComponent() = default;
		TagComponent(const TagComponent&) = default;
		TagComponent(const std::string& tag)
			: Tag(tag) {}
	};

	struct TransformComponent
	{
		glm::mat4 Transform = glm::mat4(1.0f);

		TransformComponent() = default;
		TransformComponent(const TransformComponent&) = default;
		TransformComponent(const glm::mat4& transform)
			: Transform(transform) {}

		operator glm::mat4& () { return Transform; }
		operator const glm::mat4& () { return Transform; }
	};

	struct Sprite2DComponent
	{
		Ref<OpenGLTexture> texture;
		glm::vec4 Color = glm::vec4(1.f);

		Sprite2DComponent() = default;
		Sprite2DComponent(const Sprite2DComponent&) = default;
		Sprite2DComponent(glm::vec4 color)
			: Color(color) {}
		Sprite2DComponent(const std::string& texturePath)
		{
			texture = OpenGLTexture::Create(texturePath);
		}
	};

	struct TextureComponent
	{
		Ref<OpenGLTexture> texture;
		unsigned int TextureSlot[32];

		TextureComponent() = default;
		TextureComponent(const TextureComponent&) = default;
		TextureComponent(const std::string& texturePath)
		{
			texture = OpenGLTexture::Create(texturePath);
		}
	};

	struct ShaderComponent
	{
		Ref<OpenGLShader> Shader;

		ShaderComponent() = default;
		ShaderComponent(const ShaderComponent&) = default;
		ShaderComponent(const char* vertexShaderFile, const char* fragmentShaderFile)
		{
			Shader = OpenGLShader::Create(vertexShaderFile, fragmentShaderFile);
		}
	};
}