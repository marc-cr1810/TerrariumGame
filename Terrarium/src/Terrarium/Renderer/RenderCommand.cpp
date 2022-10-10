#include "tepch.h"
#include "Terrarium/Renderer/RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Terrarium
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}