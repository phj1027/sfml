#include "framework.h" 
#include "Scene.h"
#include "Object.h" 

Scene::Scene()
{
	Init();
}

Scene::Scene(stack<Scene*>* scenes) : scenes(scenes) 
{
	Init();
}

Scene::~Scene()
{

}

void Scene::Init()
{
	
}

void Scene::EndScene()
{
	quit = true;
}

bool Scene::GetQuit() const
{
	return quit;
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