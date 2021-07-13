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
													//ㄴ> Scene.cpp에서는 scenes(scenes)인데 여긴 Scene(scenes)인 이유 : 자신의 부모클래스의 생성자((stack<Scene*>* scenes)==매개변수를 받는 생성자)는 똑같이 쓰겠다는 뜻 
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
