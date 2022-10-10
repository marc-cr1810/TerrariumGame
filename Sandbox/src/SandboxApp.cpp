#include <Terrarium.h>
#include <Terrarium/Core/EntryPoint.h>

class SandboxApp : public Terrarium::Application
{
public:
	SandboxApp(const Terrarium::ApplicationSpecification& spec)
		: Terrarium::Application(spec)
	{
		TE_INFO("Hello World!");
	}
};

Terrarium::Application* Terrarium::CreateApplication(Terrarium::ApplicationCommandLineArgs args)
{
	Terrarium::ApplicationSpecification spec;
	spec.Name = "Terrarium Sandbox Demo";
	spec.CommandLineArgs = args;

	return new SandboxApp(spec);
}