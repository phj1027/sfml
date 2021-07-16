#include "framework.h"
#include "TutorialScene.h"
#include "BackGroundObject.h"
#include "FirstStageScene.h"
#include "PauseScene.h"
#include "Character.h"

TutorialScene::TutorialScene()
{
	Init();
}

TutorialScene::TutorialScene(stack<Scene*>* scenes,RenderWindow* window, SoundSystem* soundSystem)
	:Scene(scenes, window,soundSystem)
{
	Init();
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::Init()
{

	Object* backGround = new BackGroundObject("Textures/Adventure Time with Finn and Jake/Background/Treehouseeembottom.png");
	animationObjects.push_back(backGround);
	animationObjects.push_back(new Character);


}

void TutorialScene::Input(Event* e)
{
	switch (e->key.code)
	{

	case Keyboard::Enter:
	{
		scenes->push(new FirstStageScene(scenes,window, soundSystem));
		cout << "FirstStageScene Scene\n";
		break;
	}
	case Keyboard::Q:
	{
		scenes->push(new PauseScene(scenes, window,soundSystem));
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
