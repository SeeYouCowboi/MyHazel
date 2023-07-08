#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Hazel
{
	class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// 在客户端中进行定义
	Application* CreateApplication();
}


