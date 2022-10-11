#include "tepch.h"
#include "Terrarium/Renderer/UniformBuffer.h"

#include "Terrarium/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLUniformBuffer.h"

namespace Terrarium
{
	Ref<UniformBuffer> UniformBuffer::Create(uint32_t size, uint32_t binding)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    TE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLUniformBuffer>(size, binding);
		}

		TE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}