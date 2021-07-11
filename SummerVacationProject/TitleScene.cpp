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
	vObjects.push_back(new BackGroundObject("Textures/Adventure Time with Finn and Jake/Background/d.png"));
	
	Font* font = new Font;
	font->loadFromFile("Font/CookieRun_Bold.ttf");
	Text* text = new Text("Press Space Key", *font);
	text->setFillColor(Color::White);
	text->setOrigin(text->getLocalBounds().width / 2.f, text->getLocalBounds().height / 2.f);
	text->setPosition(Vector2f(1040 / 2.f, 530.f));
	mTexts["TITLE"] = text;
}


void TitleScene::Destroy()
{

}

void TitleScene::Update(const float& deltaTime)
{
	static float elapsedTime = 0.f;

	static float txtScale = 1.f; // �ʱⰪ�� 1�� / �ִ밪 1.3��~������ 1.0 

	static int frame = 0;
	static int div = 1;

	if ((elapsedTime += deltaTime) >= 0.03f)
	{
		if ((++frame % 30) == 0)
		{
			div *= -1;
		}
		txtScale += (0.01f * div); // 0.01�� 30���ϸ� 0.3  -> �ʱⰪ 1�̴ϱ� 1����~1.3 �Դٰ����ϴ°�
		mTexts["TITLE"]->setScale(Vector2f(txtScale, txtScale));
		elapsedTime = 0.f;
	}
	Scene::Update(deltaTime);
}

void TitleScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
