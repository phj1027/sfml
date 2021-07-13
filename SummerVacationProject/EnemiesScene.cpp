#include "framework.h"
#include "EnemiesScene.h"
#include "SignMonster.h"
#include "BigZombie.h"

EnemiesScene::EnemiesScene()
{
	Init();
}

EnemiesScene::EnemiesScene(stack<Scene*>* scenes, RenderWindow* window)
	:Scene(scenes, window)
													//��> Scene.cpp������ scenes(scenes)�ε� ���� Scene(scenes)�� ���� : �ڽ��� �θ�Ŭ������ ������((stack<Scene*>* scenes)==�Ű������� �޴� ������)�� �Ȱ��� ���ڴٴ� �� 
{
	Init();
}

EnemiesScene::~EnemiesScene()
{
}

void EnemiesScene::Init()
{
	animationObjects.push_back(new SignMonster);
	animationObjects.push_back(new BigZombie);
}

void EnemiesScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void EnemiesScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}

void EnemiesScene::Input(Event* e)
{
}
