#pragma once

#include "Terrarium/Core/Base.h"
#include "Terrarium/Core/Application.h"

#ifdef TE_PLATFORM_WINDOWS

extern Terrarium::Application* Terrarium::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Terrarium::Log::Init();
	TE_CORE_INFO("Initialized Log!");

	TE_PROFILE_BEGIN_SESSION("Startup", "TerrariumProfile-Startup.json");
	auto app = Terrarium::CreateApplication({ argc, argv });
	TE_PROFILE_END_SESSION();

	TE_PROFILE_BEGIN_SESSION("Runtime", "TerrariumProfile-Runtime.json");
	app->Run();
	TE_PROFILE_END_SESSION();

	TE_PROFILE_BEGIN_SESSION("Shutdown", "TerrariumProfile-Shutdown.json");
	delete app;
	TE_PROFILE_END_SESSION();
}

#endif