#include "Game.h"

Sandbox::Sandbox()
	: Layer("Sandbox")
{
	Engine::LOG_INFO("Starting Sandbox...");
}

Sandbox::~Sandbox()
{
	
}

void Sandbox::OnAttach()
{
	Engine::Instance instance = Engine::Instance::GetInstance();

	Engine::ImGuiLayer::b_ShowStatistics = true;
	Engine::ImGuiLayer::b_ShowDemoWindow = false;

	//auto& player = Engine::Entities::AddEntity("Player");
	//
	//Engine::Vertex playerVertex;
	//playerVertex.color = glm::vec3(1.0f);
	//playerVertex.position = glm::vec3(0.0f);
	//playerVertex.texCoords = glm::vec3(0.0f);
	//
	//Engine::Entities::AddComponent(player, Engine::texture);
	//Engine::Entities::AddComponent(player, Engine::mesh);
	//Engine::Entities::AddComponent(player, Engine::shader);

// ---------------------------------------------------------------------
	
}

void Sandbox::OnDetach()
{

}

void Sandbox::OnUpdate(Engine::TimeStep ts)
{

}