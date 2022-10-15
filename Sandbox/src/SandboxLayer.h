#pragma once

#include <Terrarium.h>
#include <Terrarium/Scene/SceneCamera.h>

#include "World/World.h"

using namespace Terrarium;

class SandboxLayer : public Layer
{
public:
	SandboxLayer();
	virtual ~SandboxLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Event& e) override;
private:
	bool OnKeyPressed(KeyPressedEvent& e);
	bool OnMouseButtonPressed(MouseButtonPressedEvent& e);

	bool OnWindowResized(WindowResizeEvent& e);

	glm::vec2 GetOpenGLPos(glm::vec2 mousePosition);
private:
	SceneCamera m_Camera;
	glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
	glm::mat4 m_CameraTransform;
	int m_ScreenWidth, m_ScreenHeight;
	float m_UpdateTime = 0;

	World m_World = World(8, 8);

	Material* m_SelectedMaterial = Materials::Dirt;
};