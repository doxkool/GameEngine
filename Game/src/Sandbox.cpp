#include "Sandbox.h"

Sandbox::Sandbox()
{
	Engine::Logger::Set_Engine_LogLevel(0);

	LOG_G_INFO("Starting Sandbox...");

	Engine::Shader::CreateVertexShader("Game/Shaders/vertex_default.glsl");
	Engine::Shader::CreateFragmentShader("Game/Shaders/fragment_default.glsl");

	Engine::WinWindow::EnableVsync(1);
	

	//Engine::Camera camera(glm::vec3(0.0f), glm::vec3(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
}

void Sandbox::OnUpdate(Engine::TimeStep ts)
{
	
}