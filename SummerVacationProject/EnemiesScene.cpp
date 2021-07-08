#include "framework.h"
#include "EnemiesScene.h"
#include "SignMonster.h"
#include "BigZombie.h"

EnemiesScene::EnemiesScene()
{
	Init();
}

EnemiesScene::~EnemiesScene()
{
}

void EnemiesScene::Init()
{
	vObjects.push_back(new SignMonster);
	vObjects.push_back(new BigZombie);
}

void EnemiesScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void EnemiesScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
