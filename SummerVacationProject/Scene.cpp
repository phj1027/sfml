#include "framework.h" // framework�� �׻� ������
#include "Scene.h"
#include "Object.h" // vector<Object*> vObjects;�� Object����ϱ� ���� 
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