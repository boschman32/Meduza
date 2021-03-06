#pragma once

#include "Platform/General/Gfx/ImGuiRenderer.h"

namespace meduza
{

	class ImGuiRendererGL : public ImGuiRenderer
	{
	public:
		ImGuiRendererGL(renderer::Renderer&);
		~ImGuiRendererGL() override;

		void Clear() override;
		virtual void Render() override;
	};
}