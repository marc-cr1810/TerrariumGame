#include "SandboxLayer.h"

SandboxLayer::SandboxLayer()
	: Layer("SandboxLayer")
{ }

void SandboxLayer::OnUpdate(Timestep ts)
{

}

void SandboxLayer::OnEvent(Event& e)
{
	TE_TRACE(e.ToString());
}

bool SandboxLayer::OnKeyPressed(KeyPressedEvent& e)
{
	return false;
}

bool SandboxLayer::OnMouseButtonPressed(MouseButtonPressedEvent& e)
{
	return false;
}
