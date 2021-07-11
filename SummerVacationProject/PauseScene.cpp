
#include "framework.h"
#include "PauseScene.h"

PauseScene::PauseScene()
{
	Init();
}

PauseScene::PauseScene(stack<Scene*>* scenes)
	:Scene(scenes)
{
	Init();
}

PauseScene::~PauseScene()
{
}

void PauseScene::Init()
{
}

void PauseScene::Input(Event* e)
{
}

void PauseScene::Destroy()
{
}

void PauseScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void PauseScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}