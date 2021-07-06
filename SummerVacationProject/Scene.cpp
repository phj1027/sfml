#include "framework.h" // framework는 항상 맨위에
#include "Scene.h"
#include "Object.h" // vector<Object*> vObjects;의 Object사용하기 위해 
#include "Character.h"
#include "SignMonster.h"
#include "BigZombie.h"


Scene::Scene()
{
	Init();
}

Scene::~Scene()
{

}

void Scene::Init()
{
	vObjects.push_back(new Character);
	vObjects.push_back(new SignMonster);
	vObjects.push_back(new BigZombie);
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
}