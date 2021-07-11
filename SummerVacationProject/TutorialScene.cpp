#include "framework.h"
#include "TutorialScene.h"
#include "BackGroundObject.h"
#include "FirstStageScene.h"
#include "PauseScene.h"

TutorialScene::TutorialScene()
{
	Init();
}

TutorialScene::TutorialScene(stack<Scene*>* scenes)
	:Scene(scenes)
{
	Init();
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Init()
{
	//vObjects.push_back(new BackGroundObject(""));
}

void TutorialScene::Input(Event* e)
{
	switch (e->key.code)
	{

	case Keyboard::Space:
	{
		scenes->push(new FirstStageScene(scenes));
		cout << "FirstStageScene Scene\n";
		break;
	}
	case Keyboard::Q:
	{
		scenes->push(new PauseScene(scenes));
		cout << "Pause Scene\n";
		break;
	}
	default:
		break;
	}
}
void TutorialScene::Destroy()
{
}


void TutorialScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void TutorialScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
