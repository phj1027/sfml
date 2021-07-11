#include "framework.h"
#include "TitleScene.h"
#include "BackGroundObject.h"
#include "TutorialScene.h"
#include "PauseScene.h"

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
	text->setPosition(Vector2f(1050 / 2.f, 530.f));
	mTexts["TITLE"] = text;
}


void TitleScene::Input(Event* e)
{
	switch (e->key.code)
	{
	case Keyboard::Escape: // titlescene에서 Q를 누르면 
	{
		scenes->top()->EndScene(); // 지금 top은 titlescene자기자신 -> 자신을 없앤다는것
		break;
	}
	case Keyboard::Space:
	{
		scenes->push(new TutorialScene(scenes));
		cout << "Tutorial Scene\n";
		break;
	}
	case Keyboard::Q:
	{
		scenes->push(new PauseScene(scenes));
		cout << "Pause Scene\n";
		break;
	}
	default:
		break;
	}


}

void TitleScene::Destroy()
{

}

void TitleScene::Update(const float& deltaTime)
{
	static float elapsedTime = 0.f;

	static float txtScale = 1.f; // 초기값이 1임 / 최대값 1.3임~최저값 1.0 

	static int frame = 0;
	static int div = 1;

	if ((elapsedTime += deltaTime) >= 0.03f)
	{
		if ((++frame % 30) == 0)
		{
			div *= -1;
		}
		txtScale += (0.01f * div); // 0.01에 30곱하면 0.3  -> 초기값 1이니까 1에서~1.3 왔다갔다하는것
		mTexts["TITLE"]->setScale(Vector2f(txtScale, txtScale));
		elapsedTime = 0.f;
	}
	Scene::Update(deltaTime);
}

void TitleScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
