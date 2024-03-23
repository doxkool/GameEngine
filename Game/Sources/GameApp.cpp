#include "Engine.h"

#include <Core/EntryPoint.h>

class Game : public Engine::Instance
{
public:
	Game(const Engine::InstanceSpec& spec)
		: Engine::Instance(spec)
	{
		//PushLayer(new EditorLayer());
	}

	~Game()
	{
	}
};

Engine::Instance* Engine::CreateInstance(Engine::InstanceSpec)
{
	InstanceSpec Spec;
	Spec.Name = "Game";
	Spec.WorkingDirectory = "../Game";
	Spec.Window_Width = 1280;
	Spec.Window_Height = 720;
	Spec.Window_Resizeable = true;

	return new Game(Spec);
}