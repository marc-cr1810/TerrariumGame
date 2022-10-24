#include "GameLayer.h"

#include <imgui/imgui.h>

GameLayer::GameLayer()
	: Layer("GameLayer")
{
}

void GameLayer::OnAttach()
{
	m_Camera = SceneCamera();
	m_Camera.SetOrthographic(10.0f, -1.0f, 1.0f);
	m_Camera.SetViewportSize(m_ScreenWidth = 1280, m_ScreenHeight = 720);

	// Camera transform
	m_CameraTransform = glm::translate(glm::mat4(1.0f), m_CameraPosition);

	// Load textures
	m_GrassDirtTextures = Texture2D::Create("assets/textures/tiles/grass_dirt.png");
	m_Dirt = SubTexture2D::CreateFromCoords(m_GrassDirtTextures, { 0, 0 }, { 8, 8 });

	m_Registry.Register("dirt", m_Dirt);
}

void GameLayer::OnDetach()
{

}

void GameLayer::OnUpdate(Timestep ts)
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

	Renderer2D::ResetStats();
	RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	RenderCommand::Clear();

	Renderer2D::BeginScene((Camera)m_Camera, m_CameraTransform);

	Renderer2D::DrawQuad(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f)), m_Registry.GetValue("dirt"));

	Renderer2D::EndScene();
}

void GameLayer::OnImGuiRender()
{
	ImGui::Begin("Render Stats");

	auto stats = Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::End();
}

void GameLayer::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowResizeEvent>(TE_BIND_EVENT_FN(GameLayer::OnWindowResized));
	dispatcher.Dispatch<KeyPressedEvent>(TE_BIND_EVENT_FN(GameLayer::OnKeyPressed));
	dispatcher.Dispatch<MouseButtonPressedEvent>(TE_BIND_EVENT_FN(GameLayer::OnMouseButtonPressed));
}

bool GameLayer::OnKeyPressed(KeyPressedEvent& e)
{
	return false;
}

bool GameLayer::OnMouseButtonPressed(MouseButtonPressedEvent& e)
{
	return false;
}

bool GameLayer::OnWindowResized(WindowResizeEvent& e)
{
	m_Camera.SetViewportSize(m_ScreenWidth = e.GetWidth(), m_ScreenHeight = e.GetHeight());

	return true;
}

glm::vec2 GameLayer::GetOpenGLPos(glm::vec2 mousePosition)
{
	float orthoWidth = (m_Camera.GetOrthographicSize() * m_Camera.GetAspectRatio()) * 0.5;
	float orthoHeight = m_Camera.GetOrthographicSize() * 0.5f;

	float x = -(orthoWidth - (Input::GetMouseX() / m_ScreenWidth) * (m_Camera.GetOrthographicSize() * m_Camera.GetAspectRatio()));
	float y = orthoHeight - ((Input::GetMouseY() / m_ScreenHeight) * m_Camera.GetOrthographicSize());

	return { x + m_CameraPosition.x - 0.5f, y + m_CameraPosition.y - 0.5f };
}
