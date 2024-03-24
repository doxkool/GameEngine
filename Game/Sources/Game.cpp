#include "Game.h"


Sandbox::Sandbox()
	: Layer("Sandbox")
{
	Engine::LOG_INFO("Starting Sandbox...");
}

Sandbox::~Sandbox()
{
	//Engine::Renderer2D::Shutdown();
}

void Sandbox::OnAttach()
{
	Engine::ImGuiLayer::b_ShowStatistics = true;
	Engine::ImGuiLayer::b_ShowDemoWindow = false;

	auto& player = Engine::Entities::AddEntity("Player");
	
	Engine::Vertex playerVertex;
	playerVertex.color = glm::vec3(1.0f);
	playerVertex.position = glm::vec3(0.0f);
	playerVertex.texCoords = glm::vec3(0.0f);
	
	Engine::Entities::AddComponent(player, Engine::texture);
	Engine::Entities::AddComponent(player, Engine::mesh);
	Engine::Entities::AddComponent(player, Engine::shader);

	//Engine::Entities::SetTextureComponent(player, std::string("Assets/Textures/Default_Tex.jpg"));
	//Engine::Entities::AddMeshComponent(player, playerVertex);
	//Engine::Entities::AddShaderComponent(player, "Assets/Shaders/vertex_basic.glsl", "Assets/Shaders/fragment_basic.glsl");
}

void Sandbox::OnDetach()
{

}

void Sandbox::OnUpdate(Engine::TimeStep ts)
{

}