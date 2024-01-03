#include "Core/LayerStack.h"

namespace Engine
{
	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers)
		{
			layer->OnDetach();
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
		m_LayerInsertIndex++;
		LOG_E_TRACE("LayerStack updated : \n# Action : Push Layer\n# Name : {} \n# ID : {}", layer->GetName(), m_LayerInsertIndex);
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
		LOG_E_TRACE("LayerStack updated : \n# Action : Push Overlay\n# Name : {}", overlay->GetName());
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);
		if (it != m_Layers.begin() + m_LayerInsertIndex)
		{
			layer->OnDetach();
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}
		LOG_E_TRACE("LayerStack updated : \n# Action : Pop Layer\n# Name : {} \n# ID : {}", layer->GetName(), m_LayerInsertIndex);
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			overlay->OnDetach();
			m_Layers.erase(it);
		}
		LOG_E_TRACE("LayerStack updated : \n# Action : Pop Overlay\n# Name : {}", overlay->GetName());
	}
}