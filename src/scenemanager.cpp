#pragma once
#include "scenemanager.hpp"

const std::size_t SceneManager::GetNumberOfQueuedScenes() const
{
	return m_sceneList.size();
}

void SceneManager::QueueSceneChange(IScene* sceneToAdd)
{
	m_sceneList.push_back(sceneToAdd);
	m_hasSceneChanged = true;
}

void SceneManager::UpdateScenes(Engine* eng)
{
	if (m_hasSceneChanged)
	{
		changeScene(eng);
		m_hasSceneChanged = false;
	}
	std::size_t size = GetNumberOfQueuedScenes();
	if (!size)
		return;
	if (size > 1)
		changeScene(eng);
	m_sceneList.front()->Update(eng);
}

void SceneManager::changeScene(Engine* eng)
{
	std::size_t size = GetNumberOfQueuedScenes();
	if (size == 1)
		m_sceneList.front()->Initialize(eng);
	while (size > 1)
	{
		m_sceneList.front()->OnSceneDestroy(eng);
		m_sceneList.pop_front();
		m_sceneList.front()->Initialize(eng);
	}
}
