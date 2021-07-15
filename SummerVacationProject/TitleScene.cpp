#include "framework.h"
#include "TitleScene.h"
#include "BackGroundObject.h"
#include "TutorialScene.h"
#include "PauseScene.h"


TitleScene::TitleScene()
{
	Init();
}

TitleScene::TitleScene(stack<Scene*>* scenes, RenderWindow* window) : Scene(scenes, window)
{
	Init();
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{
	music.openFromFile("Sound/100116happybgm.wav");
	music.play();

	animationObjects.push_back(new BackGroundObject("Textures/Adventure Time with Finn and Jake/Background/T.png"));

	//Font* font = new Font;
	//font->loadFromFile("Font/CookieRun_Bold.ttf");
	//Text* text = new Text("Press Enter Key", *font);
	//text->setFillColor(Color::White);
	//text->setOrigin(text->getLocalBounds().width / 2.f, text->getLocalBounds().height / 2.f);
	//text->setPosition(Vector2f(1325 / 2.f, 500.f));
	//mTexts["TITLE"] = text;
	mButtons["PLAY"] = new Button("Textures/Adventure Time with Finn and Jake/Button/start-button.png", 
									"Textures/Adventure Time with Finn and Jake/Button/PlayButtonaction.png", 
										Vector2f(1315 / 2.f, 630.f));
}


void TitleScene::Input(Event* e)
{
	switch (e->key.code)
	{
	case Keyboard::Escape: 
	{
		scenes->top()->EndScene(); // 지금 top은 titlescene자기자신 -> 자신을 없앤다는것
		break;
	}
	case Keyboard::Enter:
	{
		scenes->push(new TutorialScene(scenes, window));
		cout << "Tutorial Scene\n";
		break;
	}
	case Keyboard::Q:
	{
		scenes->push(new PauseScene(scenes, window));
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
	if (mButtons["PLAY"]->IsPressed())
	{
		scenes->push(new TutorialScene(scenes, window));
	}
	Scene::Update(deltaTime);
}

void TitleScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
