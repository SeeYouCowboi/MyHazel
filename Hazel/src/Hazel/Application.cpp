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
		// ��ΪSetEventCallback() ���ܵ�������func<void(&Event)> ����������Ҫ��OnEvent()����ȥ
		// ����Ҫ����ʹ��bind������ȥ������������˼���൱��SetEventCallBack(OnEvent())
	}

	Application::~Application() 
	{

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	void Application::OnEvent(Event& e) 
	{
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
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