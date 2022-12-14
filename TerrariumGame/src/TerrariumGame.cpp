#include <Terrarium.h>
#include <Terrarium/Core/EntryPoint.h>

#include "GameLayer.h"

#include "Core/Textures.h"

#include "World/Level/Material/Materials.h"
#include "World/Level/Tile/Tiles.h"

class TerrariumGame : public Terrarium::Application
{
public:
	TerrariumGame(const Terrarium::ApplicationSpecification& spec)
		: Terrarium::Application(spec)
	{
		GetWindow().SetVSync(false);

		Textures::Init();
		Materials::Init();
		Tiles::Init();

		PushLayer(new GameLayer());
	}
};

Terrarium::Application* Terrarium::CreateApplication(ApplicationCommandLineArgs args)
{
	srand(time(NULL));

	Terrarium::ApplicationSpecification spec;
	spec.Name = "Terrarium Game Demo";
	spec.CommandLineArgs = args;

	return new TerrariumGame(spec);
}