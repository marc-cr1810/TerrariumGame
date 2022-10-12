#include "SandboxLayer.h"

SandboxLayer::SandboxLayer()
	: Layer("SandboxLayer")
{ }

void SandboxLayer::OnAttach()
{
	m_Camera = SceneCamera();
	m_Camera.SetOrthographic(10.0f, -1.0f, 1.0f);
	m_Camera.SetViewportSize(1280, 720);

	// Camera transform
	glm::vec3 translation = { 0.0f, 0.0f, 0.0f };
	m_CameraTransform = glm::translate(glm::mat4(1.0f), translation);
}

void SandboxLayer::OnDetach()
{

}

void SandboxLayer::OnUpdate(Timestep ts)
{
	Renderer2D::ResetStats();
	RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	RenderCommand::Clear();

	Renderer2D::BeginScene((Camera)m_Camera, m_CameraTransform);

	Renderer2D::DrawQuad(glm::translate(glm::mat4(1.0f), { 0.0f, 0.0f, 0.0f }), { 1.0f, 0.0f, 1.0f, 1.0f });

	Renderer2D::EndScene();
}

void SandboxLayer::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowResizeEvent>(TE_BIND_EVENT_FN(SandboxLayer::OnWindowResized));
}

bool SandboxLayer::OnKeyPressed(KeyPressedEvent& e)
{
	return false;
}

bool SandboxLayer::OnMouseButtonPressed(MouseButtonPressedEvent& e)
{
	return false;
}

bool SandboxLayer::OnWindowResized(WindowResizeEvent& e)
{
	m_Camera.SetViewportSize(e.GetWidth(), e.GetHeight());

	return true;
}
