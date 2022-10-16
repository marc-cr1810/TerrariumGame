#include <Terrarium.h>
#include <Terrarium/Core/EntryPoint.h>

#include "SandboxLayer.h"
#include "Utils/Random.h"

class SandboxApp : public Terrarium::Application
{
public:
	SandboxApp(const Terrarium::ApplicationSpecification& spec)
		: Terrarium::Application(spec)
	{
		PushLayer(new SandboxLayer());
	}
};

Terrarium::Application* Terrarium::CreateApplication(ApplicationCommandLineArgs args)
{
	Random::Init();
	srand(time(NULL));

	Terrarium::ApplicationSpecification spec;
	spec.Name = "Terrarium Sandbox Demo";
	spec.CommandLineArgs = args;

	return new SandboxApp(spec);
}