#include "Sandbox.h"

// TODO :
// - Be able to move model at runtime.


Sandbox::Sandbox()
	: Layer("Sandbox"), m_camera(Engine::Perspective)
{
	Engine::Logger::Set_Engine_LogLevel(0);

	LOG_G_INFO("Starting Sandbox...");

	Engine::WinWindow::EnableVsync(1);

	Engine::RendererCMD::LoadShader("Game/Shaders/vertex_basic.glsl", "Game/Shaders/fragment_basic.glsl");

	Engine::Texture& tex1 = Engine::RendererCMD::LoadTexture("./Game/Textures/kira.jpg");
	Engine::Texture& tex2 = Engine::RendererCMD::LoadTexture("./Game/Textures/finn.jpg");
	
	Engine::Renderer2D::DrawQuad(glm::vec3(0.5f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.5f), tex1);
	Engine::Renderer2D::DrawQuad(glm::vec3(0.f, 0.5f, 0.f), glm::vec3(0.f, 0.f, 30.f), glm::vec3(1.f), tex2);
	Engine::Renderer2D::DrawTriangle(glm::vec3(-0.5f, 0.f, 0.f), glm::vec3(0.f, 0.f, 50.f), glm::vec3(0.8f), tex1);
	Engine::Renderer2D::DrawTriangle(glm::vec3(0.f, -0.5f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f), tex2);
}

Sandbox::~Sandbox()
{
	Engine::Renderer2D::Shutdown();
}


void Sandbox::OnAttach()
{
	
}

void Sandbox::OnDetach()
{
	
}

void Sandbox::OnUpdate(Engine::TimeStep ts)
{
	// Update camera
	m_camera.OnUpdate(ts);

	//Engine::Texture& tex1 = Engine::RendererCMD::LoadTexture("./Game/Textures/kira.jpg");
	//Engine::Texture& tex2 = Engine::RendererCMD::LoadTexture("./Game/Textures/finn.jpg");
	//
	//Engine::Renderer2D::DrawQuad(glm::vec3(0.5f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.5f), tex1);
	//Engine::Renderer2D::DrawQuad(glm::vec3(0.f, 0.5f, 0.f), glm::vec3(0.f, 0.f, 30.f), glm::vec3(1.f), tex2);
	//Engine::Renderer2D::DrawTriangle(glm::vec3(-0.5f, 0.f, 0.f), glm::vec3(0.f, 0.f, 50.f), glm::vec3(0.8f), tex1);
	//Engine::Renderer2D::DrawTriangle(glm::vec3(0.f, -0.5f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f), tex2);


	Engine::RendererCMD::Set_ClearColor(glm::vec4 (0.3f, 0.5f, 0.5f, 1.f));
	Engine::RendererCMD::Clear();
	Engine::RendererCMD::Render(m_camera);
}