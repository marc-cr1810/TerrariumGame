#pragma once

#include "Terrarium/Core/Base.h"

#ifdef TE_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
	Terrarium::Log::Init();
	TE_CORE_INFO("Initialized Log!");
}

#endif