#include "framework.h" 
#include "Scene.h"
#include "Object.h" 
 

Scene::Scene()
{
	Init();
}

Scene::Scene(stack<Scene*>* scenes, RenderWindow* window) : scenes(scenes), window(window)
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
	mousePosition = window->mapPixelToCoords(Mouse::getPosition(*window));

	for (auto& obj : animationObjects)
	{
		obj->Update(deltaTime);
	}

	for (auto& btn : mButtons)
	{
		btn.second->Update(mousePosition); // 버튼은 시간이아닌 포지션으로만 업데이트하게됨 
	}
}

void Scene::Render(RenderWindow* window)
{
	for (auto& obj : animationObjects)
	{
		if (obj->IsActive() == true)
		{
			window->draw(*obj);
		}
	}
	for (auto& btn : mButtons)
	{
		window->draw(*btn.second); // 버튼은 시간이아닌 포지션으로만 업데이트하게됨 
	}
	for (auto& txt : mTexts)
	{
		window->draw(*txt.second);
	}
}