#include "Sandbox.h"

// TODO :
// - Expose inputs via abstraction layer to the application.


Sandbox::Sandbox()
	: Layer("Sandbox")
{
	Engine::Logger::Set_Engine_LogLevel(0);

	LOG_G_INFO("Starting Sandbox...");

	Engine::WinWindow::EnableVsync(1);

	instance.Init();

	instance.CreateQuad(glm::vec3(0.5f, 0.f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.5f), "./Game/Textures/kira.jpg");
	instance.CreateQuad(glm::vec3(0.f, 0.5f, 0.f), glm::vec3(0.f, 0.f, 30.f), glm::vec3(1.f), "./Game/Textures/finn.jpg");
	instance.CreateTriangle(glm::vec3(-0.5f, 0.f, 0.f), glm::vec3(30.f, 0.f, 0.f), glm::vec3(1.f), "./Game/Textures/finn.jpg");
	instance.CreateTriangle(glm::vec3(0.f, -0.5f, 0.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f), "./Game/Textures/kira.jpg");
}

Sandbox::~Sandbox()
{
	instance.Shutdown();
}


void Sandbox::OnAttach()
{
	
}

void Sandbox::OnDetach()
{
	
}

void Sandbox::OnUpdate(Engine::TimeStep ts)
{
	instance.Render();
}