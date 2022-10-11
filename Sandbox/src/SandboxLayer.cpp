#include "SandboxLayer.h"

SandboxLayer::SandboxLayer()
	: Layer("SandboxLayer")
{ }

void SandboxLayer::OnAttach()
{
}

void SandboxLayer::OnDetach()
{
}

void SandboxLayer::OnUpdate(Timestep ts)
{

}

void SandboxLayer::OnEvent(Event& e)
{

}

bool SandboxLayer::OnKeyPressed(KeyPressedEvent& e)
{
	return false;
}

bool SandboxLayer::OnMouseButtonPressed(MouseButtonPressedEvent& e)
{
	return false;
}
