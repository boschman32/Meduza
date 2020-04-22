#include "mePch.h"

#include "Platform/General/Renderer.h"

#ifdef WIN

#include "Platform/Windows/WinWindow.h"
#include "Platform/Windows/Gfx/OpenGL/RendererGL.h"

#endif

meduza::Window* meduza::renderer::Renderer::m_window = nullptr;
 
meduza::renderer::Renderer* meduza::renderer::Renderer::CreateRenderer(API a_api, math::Vec2 a_size)
{
	switch (a_api)
	{
	case meduza::API::OpenGL:
#ifdef WIN
		m_window = new WinWindow(a_size, a_api);
		return new RendererGL();
#else // WIN
		break;
#endif
	case meduza::API::DirectX12:

#ifdef WIN
		m_window = new WinWindow(a_size, a_api);
		return nullptr;
#else // WIN
		break;
#endif
	default:
		break;
	}

	return nullptr;
}

meduza::Window& meduza::renderer::Renderer::GetWindow() const
{
	assertm(m_window != nullptr, "There is no Window!");

	return *this->m_window;
}
