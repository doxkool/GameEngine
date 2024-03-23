#include "Game.h"


namespace Game
{

}



















//int main(int argc, char** argv)
//{	
//	Instance instance;
//
//	instance.SetWindow("Game", 1280, 720, true);
//
//	auto& Window = instance.GetWindow();
//	auto& Entities = instance.GetEntities();
//	auto& Shader = instance.GetShader();
//
//	TimeStep ts;
//
//	ImGuiLayer::b_ShowStatistics = true;
//	ImGuiLayer::b_ShowDemoWindow = true;
//
//	//auto& player = Entities::AddEntity("Player");
//	//
//	//Vertex playerVertex;
//	//playerVertex.color = glm::vec3(1.0f);
//	//playerVertex.position = glm::vec3(0.0f);
//	//playerVertex.texCoords = glm::vec3(0.0f);
//	//
//	//Entities::AddComponent(player, texture);
//	//Entities::AddComponent(player, mesh);
//	//Entities::AddComponent(player, shader);
//
//	//Entities::SetTextureComponent(player, std::string("Assets/Textures/Default_Tex.jpg"));
//	//Entities::AddMeshComponent(player, playerVertex);
//	//Entities::AddShaderComponent(player, "Assets/Shaders/vertex_basic.glsl", "Assets/Shaders/fragment_basic.glsl");
//
//	while (!Window.Get_WindowShouldClose())
//	{
//		Perf::StartPerfCounter(ts);
//
//		auto& Entities = instance.GetEntities();
//
//		// OpenGL clear.
//		OpenGL::Set_ClearColor(glm::vec4(0.5f, 0.5f, 0.5f, 0.f));
//		OpenGL::Clear();
//
//		// Update.
//		Window.Update();
//		Entities.OnUpdate(ts);
//
//		// Render
//		//Renderer2D::DrawQuadVT(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec2(1.f, 1.f), tex);
//		//Renderer2D::Render();
//
//		// ImGui New Frame
//		ImGuiLayer::NewFrame();
//		ImGuiLayer::Render();
//
//		// Swap the Buffer
//		Window.SwapBuffer();
//
//		// End performance counter.
//		Perf::EndPerfCounter();
//	}
//
//	return 0;
//}