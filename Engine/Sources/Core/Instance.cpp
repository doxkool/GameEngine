#include "Core/Instance.h"

namespace Engine
{
	OpenGLWindow Window;
	const OpenGLInput Input;
	Ref<OpenGLVertexArray> VAO;
	Ref<OpenGLVertexBuffer> VBO;
	Ref<OpenGLElementBuffer> EBO;
	Ref<OpenGLIndexBuffer> IBO;
	Ref<OpenGLShader> Shader;
	Ref<OpenGLTexture> Texture;

	Instance* Instance::s_Instance = nullptr;

	Instance::Instance(const InstanceSpec& specification)
		: m_Specification(specification)
	{
		Logger::Init();

		s_Instance = this;

		Window.SetWindow(specification.Name, specification.Window_Width, specification.Window_Height, specification.Window_Resizeable);

		auto m_Window = Window.GetNativeWindow();

		OpenGL::Init();

		// Setup window user pointer
		Window.SetWindowUserPointer(Window);
		// Setup window Callback
		WindowCallback WindowCallback(Window);

		m_ImGuiLayer = new ImGuiLayer(Window.GetNativeWindow());
		PushOverlay(m_ImGuiLayer);

		Window.EnableVsync(1);

		renderer2D.Init();
	}

	void Instance::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Instance::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Instance::Run()
	{
		TimeStep ts;

		while (!Window.Get_WindowShouldClose())
		{
			Perf::StartPerfCounter(ts);

			//auto& Entities = GetEntities();

			// OpenGL clear.
			OpenGL::Set_ClearColor(glm::vec4(0.5f, 0.5f, 0.5f, 0.f));
			OpenGL::Clear();

			// Update.
			Window.Update();
			Entities.OnUpdate(ts);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(ts);

			// ImGui New Frame
			ImGuiLayer::NewFrame();
			ImGuiLayer::Render();

			renderer2D.Render();

			// Swap the Buffer
			Window.SwapBuffer();

			// End performance counter.
			Perf::EndPerfCounter();
		}
	}

	OpenGLWindow Instance::GetWindow() { return Window; }
	OpenGLInput Instance::GetInput() const { return Input; }
	Ref<OpenGLVertexArray> Instance::GetVAO() { return VAO; }
	Ref<OpenGLVertexBuffer> Instance::GetVBO() { return VBO; }
	Ref<OpenGLElementBuffer> Instance::GetEBO() { return EBO; }
	Ref<OpenGLIndexBuffer> Instance::GetIBO() { return IBO; }
	Ref<OpenGLShader> Instance::GetShader() { return Shader; }
	Ref<OpenGLTexture> Instance::GetTexture() { return Texture; }
}