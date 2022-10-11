#include "SandboxLayer.h"

SandboxLayer::SandboxLayer()
	: Layer("SandboxLayer")
{ }

void SandboxLayer::OnAttach()
{
	// Camera orthographic projection
	float orthoSize = 10.0f;
	float orthoNear = -1.0f, orthoFar = 1.0f;

	float orthoLeft = -orthoSize * m_AspectRatio * 0.5f;
	float orthoRight = orthoSize * m_AspectRatio * 0.5f;
	float orthoBottom = -orthoSize * 0.5f;
	float orthoTop = orthoSize * 0.5f;

	m_Camera = Camera(glm::ortho(orthoLeft, orthoRight, orthoBottom, orthoTop, orthoNear, orthoFar));

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

	Renderer2D::BeginScene(m_Camera, m_CameraTransform);

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
	m_AspectRatio = (float)e.GetWidth() / (float)e.GetHeight();

	// If the window is resized, change the aspect ratio and recalculate the projection matrix
	float orthoSize = 10.0f;
	float orthoNear = -1.0f, orthoFar = 1.0f;

	float orthoLeft = -orthoSize * m_AspectRatio * 0.5f;
	float orthoRight = orthoSize * m_AspectRatio * 0.5f;
	float orthoBottom = -orthoSize * 0.5f;
	float orthoTop = orthoSize * 0.5f;

	m_Camera = Camera(glm::ortho(orthoLeft, orthoRight, orthoBottom, orthoTop, orthoNear, orthoFar));

	return true;
}
