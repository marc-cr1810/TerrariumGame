#include "tepch.h"
#include "Terrarium/Renderer/Renderer.h"

namespace Terrarium
{
	void Renderer::Init()
	{
		TE_PROFILE_FUNCTION();

		RenderCommand::Init();
	}

	void Renderer::Shutdown()
	{

	}

	void Renderer::OnWindowResize(uint32_t width, uint32_t height)
	{
		RenderCommand::SetViewport(0, 0, width, height);
	}
}