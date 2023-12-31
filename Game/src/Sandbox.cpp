#include "Sandbox.h"

Sandbox::Sandbox()
{
	Engine::Logger::Set_Engine_LogLevel(0);
	LOG_G_INFO("Starting Sandbox...");
	Engine::WinWindow::EnableVsync(1);
	
	// TODO : Load the shaders relative to the working directory.
	Engine::Shader shaderProgram(4, 5, "vertex_core.glsl", "fragment_core.glsl", NULL);
	
	shaderProgram.use();

	Engine::Camera camera(glm::vec3(0.0f), glm::vec3(0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
}