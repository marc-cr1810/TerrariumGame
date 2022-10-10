#include "Application.h"

namespace Terrarium
{
	Application* Application::s_Instance = nullptr;

	Application::Application(const ApplicationSpecification& specification)
		: m_Specification(specification)
	{
		TE_PROFILE_FUNCTION();

		TE_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		// Set the working directory here
		if (!m_Specification.WorkingDirectory.empty())
			std::filesystem::current_path(m_Specification.WorkingDirectory);
	}

	Application::~Application()
	{
		TE_PROFILE_FUNCTION();
	}
}