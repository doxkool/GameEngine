#include "Sandbox.h"

Sandbox::Sandbox()
	: Layer("Sandbox")
{
	Engine::Logger::Set_Engine_LogLevel(0);

	LOG_G_INFO("Starting Sandbox...");

	Engine::WinWindow::EnableVsync(1);

	opengl.LoadShaders("Game/Shaders/vertex_basic.glsl", "Game/Shaders/fragment_basic.glsl");

	std::vector<Engine::Vertex> Vertices;
	std::vector<GLuint> Indices;

	Engine::Vertex quad_vertices[] =
	{
		//Position								//Color					
		glm::vec3(-0.5f, 0.5f, 0.f),			glm::vec3(1.f, 0.f, 0.f),
		glm::vec3(-0.5f, -0.5f, 0.f),			glm::vec3(0.f, 1.f, 0.f),
		glm::vec3(0.5f, -0.5f, 0.f),			glm::vec3(0.f, 0.f, 1.f),
		glm::vec3(0.5f, 0.5f, 0.f),				glm::vec3(1.f, 1.f, 0.f)
	};

	for (size_t i = 0; i < sizeof(quad_vertices) / sizeof(quad_vertices[0]); i++)
	{
		Vertices.push_back(quad_vertices[i]);
	}

	GLuint quad_indices[] =
	{
		0, 1, 2,	//Triangle 1
		0, 2, 3		//Triangle 2
	};

	for (size_t i = 0; i < sizeof(quad_indices) / sizeof(quad_indices[0]); i++)
	{
		Indices.push_back(quad_indices[i]);
	}

	opengl.LoadVBO(Vertices, Indices);

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