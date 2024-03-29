#pragma once

#include "Core/Base.h"

#include "OpenGL/OpenGL.h"

#include "OpenGL/OpenGLVertexArray.h"
#include "OpenGL/OpenGLVertexBuffer.h"
#include "OpenGL/OpenGLIndexBuffer.h"
#include "OpenGL/OpenGLElementBuffer.h"
#include "OpenGL/OpenGLTexture.h"
#include "OpenGL/OpenGLShader.h"
#include "OpenGL/OpenGLWindow.h"
#include "OpenGL/OpenGLInput.h"

#include "ImGui/ImGuiLayer.h"

#include "Core/Logger.h"
#include "Core/Utilities.h"
#include "Core/Layer.h"
#include "Core/LayerStack.h"

#include "Entities/Entities.h"

#include "Renderer/Renderer2D.h"

int main();

namespace Engine
{
	struct InstanceSpec
	{
		std::string Name = "Game";
		int Window_Width = 1280;
		int Window_Height = 720;
		bool Window_Resizeable = true;
		std::string WorkingDirectory;
	};

	class Instance
	{
	public:
		Instance(const InstanceSpec& specification);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		void Run();

		static Instance& GetInstance() { return *s_Instance; }

		OpenGLWindow GetWindow();
		OpenGLInput GetInput() const;
		Ref<OpenGLVertexArray> GetVAO();
		Ref<OpenGLVertexBuffer> GetVBO();
		Ref<OpenGLElementBuffer> GetEBO();
		Ref<OpenGLIndexBuffer> GetIBO();
		Ref<OpenGLShader> GetShader();
		Ref<OpenGLTexture> GetTexture();

		Entities& GetEntities() { return Entities; }

	private:
		InstanceSpec m_Specification;
		static Instance* s_Instance;
		LayerStack m_LayerStack;

		ImGuiLayer* m_ImGuiLayer;

		Entities Entities;

		Renderer2D renderer2D;

	};

	Instance* CreateInstance(InstanceSpec);
}