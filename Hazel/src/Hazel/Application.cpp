#include "hzpch.h"
#include "Application.h"
#include "Hazel/Events/ApplicationEvent.h"
#include "Hazel/Log.h"

#include <GLFW/glfw3.h>

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

namespace Hazel {
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
		// 因为SetEventCallback() 接受的输入是func<void(&Event)> 这里我们想要把OnEvent()传进去
		// 就需要这样使用bind来传进去。所以这里意思上相当于SetEventCallBack(OnEvent())
	}

	Application::~Application() 
	{

	}

	void Application::OnEvent(Event& e) 
	{
		HZ_CORE_INFO("{0}", e);
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}