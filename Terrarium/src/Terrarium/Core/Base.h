#pragma once

#include <memory>

#include "Terrarium/Core/PlatformDetection.h"

#ifdef TE_DEBUG
	#if defined(TE_PLATFORM_WINDOWS)
		#define TE_DEBUGBREAK() __debugbreak()
	#elif defined(TE_PLATFORM_LINUX)
		#include <signal.h>
		#define TE_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define TE_ENABLE_ASSERTS
#else
	#define TE_DEBUGBREAK()
#endif

#define TE_EXPAND_MACRO(x) x
#define TE_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define TE_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Terrarium
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}

#include "Terrarium/Core/Log.h"
#include "Terrarium/Core/Assert.h"
