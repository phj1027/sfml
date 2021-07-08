#include "framework.h"
#include "TitleScene.h"
#include "BackGroundObject.h"

TitleScene::TitleScene()
{
	Init();
}

TitleScene::TitleScene(stack<Scene*>* scenes) : Scene(scenes)
{
	Init();
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	vObjects.push_back(new BackGroundObject("Textures/Adventure Time with Finn and Jake/Background/Title_button.png"));
}

void TitleScene::Destroy()
{

}

void TitleScene::Update(const float& deltaTime)
{
	Scene::Update(deltaTime);
}

void TitleScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
