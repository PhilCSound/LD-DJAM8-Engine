#pragma once
#include <list>
#include "engine.hpp"
#include "iscene.hpp"

class IScene;

class SceneManager
{
public:
	SceneManager() = default;

	const std::size_t GetNumberOfQueuedScenes() const;
	void QueueSceneChange(IScene* sceneToAdd);
	void UpdateScenes(Engine* eng);

private:
	//Private Functions
	void changeScene(Engine* eng);

	//Private MemberVariables
	std::list<IScene*> m_sceneList;
};