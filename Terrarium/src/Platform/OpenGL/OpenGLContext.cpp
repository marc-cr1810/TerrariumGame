#include "tepch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Terrarium
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		TE_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		TE_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		TE_CORE_ASSERT(status, "Failed to initialize Glad!");

		TE_CORE_INFO("OpenGL Info:", glGetString(GL_VENDOR), glGetString(GL_RENDERER));
		TE_CORE_INFO("  Vendor:	{0}", glGetString(GL_VENDOR));
		TE_CORE_INFO("  Renderer:	{0}", glGetString(GL_RENDERER));
		TE_CORE_INFO("  Version:	{0}", glGetString(GL_VERSION));

		TE_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Terrarium requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		TE_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}
}