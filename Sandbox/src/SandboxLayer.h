#pragma once

#include <Terrarium.h>
#include <Terrarium/Events/KeyEvent.h>
#include <Terrarium/Events/MouseEvent.h>

using namespace Terrarium;

class SandboxLayer : public Layer
{
public:
	SandboxLayer();
	virtual ~SandboxLayer() = default;

	void OnUpdate(Timestep ts) override;
	void OnEvent(Event& e) override;
private:
	bool OnKeyPressed(KeyPressedEvent& e);
	bool OnMouseButtonPressed(MouseButtonPressedEvent& e);
};