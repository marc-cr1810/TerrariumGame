#include <Terrarium.h>
#include <Terrarium/Core/EntryPoint.h>

#include "SandboxLayer.h"

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
	Terrarium::ApplicationSpecification spec;
	spec.Name = "Terrarium Sandbox Demo";
	spec.CommandLineArgs = args;

	return new SandboxApp(spec);
}