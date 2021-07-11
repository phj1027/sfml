#include "framework.h" // framework는 항상 맨위에
#include "Scene.h"
#include "Object.h" // vector<Object*> vObjects;의 Object사용하기 위해 

Scene::Scene()
{
	Init();
}

Scene::Scene(stack<Scene*>* scenes) : scenes(scenes) // 받아오는 변수들을 자신의 멤버변수에 넣음
{
	Init();
}

Scene::~Scene()
{

}

void Scene::Init()
{
	
}


bool Scene::GetQuit() const
{
	return quit;
}

void Scene::EndScene()
{
	quit = true;
}

void Scene::Input(Event* e)
{
}

void Scene::Update(const float& deltaTime)
{
	for (auto& obj : vObjects)
	{
		obj->Update(deltaTime);
	}
}

void Scene::Render(RenderWindow* window)
{
	for (auto& obj : vObjects)
	{
		window->draw(*obj);
	}
	for (auto& txt : mTexts)
	{
		window->draw(*txt.second);
	}
}