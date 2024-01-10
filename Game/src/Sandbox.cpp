#include "Sandbox.h"

// TODO :
// - Expose inputs via abstraction layer to the application.
// - Be able the position objects on screen.

Sandbox::Sandbox()
	: Layer("Sandbox")
{
	Engine::Logger::Set_Engine_LogLevel(0);

	LOG_G_INFO("Starting Sandbox...");

	Engine::WinWindow::EnableVsync(1);

	instance.Init();

	instance.CreateQuad(glm::vec2(0.f, 0.f), "./Game/Textures/kira.jpg");
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