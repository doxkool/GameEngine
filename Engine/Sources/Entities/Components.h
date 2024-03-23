#pragma once

#include "Core/Base.h"

#include "OpenGL/OpenGLVertexArray.h"
#include "OpenGL/OpenGLVertexBuffer.h"
//#include "OpenGL/OpenGLElementBuffer.h"
#include "OpenGL/OpenGLTexture.h"
#include "OpenGL/OpenGLShader.h"

#include <glm.hpp>

namespace Engine
{
	enum ComponentType
	{
		transform,
		sprite2D,
		texture,
		mesh,
		shader
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

	struct MeshComponent
	{
		Ref<OpenGLVertexArray> VAO;
		Ref<OpenGLVertexBuffer> VBO;

		MeshComponent() = default;
		MeshComponent(const MeshComponent&) = default;
		MeshComponent(Vertex& vertex)
		{
			VAO = OpenGLVertexArray::Create();
			VBO = OpenGLVertexBuffer::Create(sizeof(vertex));

			VAO->Bind();
			VBO->Bind();

			// Links VBO Position attributes to VAO
			VAO->LinkAttrib(0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
			// Links VBO Color attributes to VAO
			VAO->LinkAttrib(1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
			// Links VBO Texcoord attributes to VAO
			VAO->LinkAttrib(2, 2, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));
			// Links VBO Normal attributes to VAO
			VAO->LinkAttrib(3, 3, GL_FLOAT, sizeof(Vertex), (void*)(9 * sizeof(float)));

			VAO->Unbind();
			VBO->Unbind();
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