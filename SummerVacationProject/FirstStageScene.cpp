#include "framework.h"
#include "FirstStageScene.h"
//#include "JellyObject.h"
#include "BackGroundObject.h"
#include "ResultScene.h"
#include "PauseScene.h"
#include "Character.h"


FirstStageScene::FirstStageScene()
{
	Init();
}

FirstStageScene::FirstStageScene(stack<Scene*>* scenes)
	:Scene(scenes)
{
	Init();
}

FirstStageScene::~FirstStageScene()
{
}

void FirstStageScene::Init()
{
	//Object* backGround = new BackGroundObject("Texture/BackGround/game.png");
	//backGround->setScale(2.5f, 2.f);
	//vObjects.push_back(backGround);
	//
	//vObjects.push_back(new Charactor);
	//
	//for (int i = 0; i < 10; ++i)
	//{
	//	jellys.push_back(new JellyObject(Orange));
	//}
	//for (int i = 0; i < 10; ++i)
	//{
	//	jellys.push_back(new JellyObject(Pupple));
	//}
	//for (int i = 0; i < 10; ++i)
	//{
	//	jellys.push_back(new JellyObject(Green));
	//}
	//
	//uniform_real_distribution<float> urd(0.f, 640.f);
	//default_random_engine dre;
	//
	//shuffle(jellys.begin(), jellys.end(), dre);
	//
	//
	//for (auto& j : jellys)
	//{
	//	j->setPosition(urd(dre), urd(dre));
	//}

}

void FirstStageScene::Input(Event* e)
{
	switch (e->key.code)
	{
	case Keyboard::Enter:
	{
		scenes->push(new ResultScene(scenes));
		cout << "ResultScene Scene\n";
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


void FirstStageScene::Destroy()
{
}


void FirstStageScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void FirstStageScene::Render(RenderWindow* window)
{
	Scene::Render(window);

	//for (auto& j : jellys)
	//{
	//	window->draw(*j);
	//}
}