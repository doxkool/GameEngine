#include "Sandbox.h"

Sandbox::Sandbox()
	: Layer("Sandbox")
{
	Engine::Logger::Set_Engine_LogLevel(0);

	LOG_G_INFO("Starting Sandbox...");

	Engine::WinWindow::EnableVsync(1);

	opengl.LoadShaders("Game/Shaders/vertex_basic.glsl", "Game/Shaders/fragment_basic.glsl");

		//Position						//Color
		//glm::vec3(0.5f, -0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f),   // bottom right
		//glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f),   // bottom left
		//glm::vec3(0.0f, 0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f)    // top

	std::vector<Engine::Vertex> Triangle;

	opengl.LoadVBO(Triangle);

	ShaderProgram = opengl.Get_ShaderProgram();
}

void Sandbox::OnAttach()
{
	
}

void Sandbox::OnDetach()
{
	
}

void Sandbox::OnUpdate(Engine::TimeStep ts)
{
	opengl.Set_ClearColor(glm::vec4(0.2f, 0.2f, 0.2f, 1.f));
	opengl.Clear();
	opengl.Draw(ShaderProgram);
}