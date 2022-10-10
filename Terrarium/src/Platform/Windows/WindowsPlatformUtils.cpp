#include "tepch.h"
#include "Terrarium/Utils/PlatformUtils.h"

#include <GLFW/glfw3.h>

#ifdef TE_PLATFORM_WINDOWS

namespace Terrarium
{
	float Time::GetTime()
	{
		return glfwGetTime();
	}
}

#endif