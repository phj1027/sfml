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
		btn.second->Update(mousePosition); // ��ư�� �ð��̾ƴ� ���������θ� ������Ʈ�ϰԵ� 
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
		window->draw(*btn.second); // ��ư�� �ð��̾ƴ� ���������θ� ������Ʈ�ϰԵ� 
	}
	for (auto& txt : mTexts)
	{
		window->draw(*txt.second);
	}
}