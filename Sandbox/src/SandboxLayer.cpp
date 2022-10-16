#include "SandboxLayer.h"

#include <imgui/imgui.h>

SandboxLayer::SandboxLayer()
	: Layer("SandboxLayer")
{
}

void SandboxLayer::OnAttach()
{
	m_Camera = SceneCamera();
	m_Camera.SetOrthographic(10.0f, -1.0f, 1.0f);
	m_Camera.SetViewportSize(m_ScreenWidth = 1280, m_ScreenHeight = 720);

	// Camera transform
	m_CameraTransform = glm::translate(glm::mat4(1.0f), m_CameraPosition);
}

void SandboxLayer::OnDetach()
{

}

void SandboxLayer::OnUpdate(Timestep ts)
{
	float speed = 4.0f * ts;
	glm::vec3 velocity = { 0.0f, 0.0f, 0.0f };

	if (Input::IsKeyPressed(Key::W))
		velocity += glm::vec3{ 0.0f, speed, 0.0f };
	if (Input::IsKeyPressed(Key::S))
		velocity += glm::vec3{ 0.0f, -speed, 0.0f };

	if (Input::IsKeyPressed(Key::A))
		velocity += glm::vec3{ -speed, 0.0f, 0.0f };
	if (Input::IsKeyPressed(Key::D))
		velocity += glm::vec3{ speed, 0.0f, 0.0f };

	m_CameraPosition += velocity;
	m_CameraTransform = glm::translate(glm::mat4(1.0f), m_CameraPosition);

	// Draw materials
	if (Input::IsMouseButtonPressed(Mouse::ButtonLeft))
	{
		glm::vec2 pos = GetOpenGLPos(Input::GetMousePosition());
		Cell* cell = m_World.GetCell(pos);
		if (cell != nullptr)
		{
			if (cell->GetMaterial() == Materials::Air || m_SelectedMaterial == Materials::Air)
				cell->SetMaterial(m_SelectedMaterial);
		}
	}

	m_UpdateTime += ts;
	if (m_UpdateTime >= 1 / 120)
	{
		m_World.Update(m_CameraPosition, { (m_Camera.GetOrthographicSize() + 2.0f) * m_Camera.GetAspectRatio(), m_Camera.GetOrthographicSize() + 2.0f });
		m_UpdateTime = 0;
	}

	Renderer2D::ResetStats();
	RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	RenderCommand::Clear();

	Renderer2D::BeginScene((Camera)m_Camera, m_CameraTransform);

	m_World.Render(m_CameraPosition, { (m_Camera.GetOrthographicSize() + 2.0f) * m_Camera.GetAspectRatio(), m_Camera.GetOrthographicSize() + 2.0f});

	Renderer2D::EndScene();
}

void SandboxLayer::OnImGuiRender()
{
	ImGui::Begin("Render Stats");

	auto stats = Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::End();

	ImGui::Begin("Terrain Editor");

	bool air = m_SelectedMaterial == Materials::Air;
	if (ImGui::Checkbox("Air", &air))
		m_SelectedMaterial = Materials::Air;

	bool dirt = m_SelectedMaterial == Materials::Dirt;
	if (ImGui::Checkbox("Dirt", &dirt))
		m_SelectedMaterial = Materials::Dirt;

	bool sand = m_SelectedMaterial == Materials::Sand;
	if (ImGui::Checkbox("Sand", &sand))
		m_SelectedMaterial = Materials::Sand;

	bool water = m_SelectedMaterial == Materials::Water;
	if (ImGui::Checkbox("Water", &water))
		m_SelectedMaterial = Materials::Water;

	ImGui::End();
}

void SandboxLayer::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowResizeEvent>(TE_BIND_EVENT_FN(SandboxLayer::OnWindowResized));
	dispatcher.Dispatch<KeyPressedEvent>(TE_BIND_EVENT_FN(SandboxLayer::OnKeyPressed));
	dispatcher.Dispatch<MouseButtonPressedEvent>(TE_BIND_EVENT_FN(SandboxLayer::OnMouseButtonPressed));
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
	m_Camera.SetViewportSize(m_ScreenWidth = e.GetWidth(), m_ScreenHeight = e.GetHeight());

	return true;
}

glm::vec2 SandboxLayer::GetOpenGLPos(glm::vec2 mousePosition)
{
	float orthoWidth = (m_Camera.GetOrthographicSize() * m_Camera.GetAspectRatio()) * 0.5;
	float orthoHeight = m_Camera.GetOrthographicSize() * 0.5f;

	float x = -(orthoWidth - (Input::GetMouseX() / m_ScreenWidth) * (m_Camera.GetOrthographicSize() * m_Camera.GetAspectRatio()));
	float y = orthoHeight - ((Input::GetMouseY() / m_ScreenHeight) * m_Camera.GetOrthographicSize());

	return { x + m_CameraPosition.x, y + m_CameraPosition.y };
}
