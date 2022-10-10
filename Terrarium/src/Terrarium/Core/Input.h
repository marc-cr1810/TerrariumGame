#pragma once

#include <glm/glm.hpp>

#include "Terrarium/Core/KeyCodes.h"
#include "Terrarium/Core/MouseCodes.h"

namespace Terrarium
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}