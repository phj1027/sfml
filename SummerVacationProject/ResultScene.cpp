#include "framework.h"
#include "ResultScene.h"
#include "TitleScene.h"

ResultScene::ResultScene()
{
	Init();
}

ResultScene::ResultScene(stack<Scene*>* scenes)
	:Scene(scenes)
{
	Init();
}

ResultScene::~ResultScene()
{
}

void ResultScene::Init()
{
}

void ResultScene::Input(Event* e)
{	
	switch (e->key.code)
	{
	case Keyboard::Enter:
	{
		scenes->push(new ResultScene(scenes));
		cout << "ResultScene Scene\n";
		break;
	}

	default:
		break;
	}
}

void ResultScene::Destroy()
{
}

void ResultScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void ResultScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}