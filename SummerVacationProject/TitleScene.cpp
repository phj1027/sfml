#include "framework.h"
#include "TitleScene.h"
#include "BackGroundObject.h"
#include "TutorialScene.h"
#include "PauseScene.h"


TitleScene::TitleScene()
{
	Init();
}

TitleScene::TitleScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem) : Scene(scenes, window, soundSystem)
{
	Init();
}

TitleScene::~TitleScene()
{
}

void TitleScene::Init()
{


	animationObjects.push_back(new BackGroundObject("Textures/Adventure Time with Finn and Jake/Background/T.png"));

	//Font* font = new Font;
	//font->loadFromFile("Font/CookieRun_Bold.ttf");
	//Text* text = new Text("Press Enter Key", *font);
	//text->setFillColor(Color::White);
	//text->setOrigin(text->getLocalBounds().width / 2.f, text->getLocalBounds().height / 2.f);
	//text->setPosition(Vector2f(1325 / 2.f, 500.f));
	//mTexts["TITLE"] = text;
	mButtons["START"] = new Button("Textures/Adventure Time with Finn and Jake/Button/start.png", 
									"Textures/Adventure Time with Finn and Jake/Button/exit.png", 
										Vector2f(1080.f, 510.f));
	mButtons["EXIT"] = new Button("Textures/Adventure Time with Finn and Jake/Button/exit.png",
		"Textures/Adventure Time with Finn and Jake/Button/PlayButtonaction.png",
		Vector2f(1080.f, 600.f));
}


void TitleScene::Input(Event* e)
{
	switch (e->type)
	{
	case Event::KeyPressed:
	{
		switch (e->key.code)
		{
		case Keyboard::Escape:
		{
			scenes->top()->EndScene(); // ���� top�� titlescene�ڱ��ڽ� -> �ڽ��� ���شٴ°�
			break;
		}

		case Keyboard::Enter:
		{
			scenes->push(new TutorialScene(scenes, window, soundSystem));

			cout << "Tutorial Scene\n";
			break;
		}
		case Keyboard::Q:
		{
			scenes->push(new PauseScene(scenes, window, soundSystem));
			cout << "Pause Scene\n";
			break;
		}
		case Keyboard::P:
		{
			soundSystem->VolumeDown();
			break;
		}
		case Keyboard::O:
		{
			soundSystem->VolumeUp();
			break;
		}
	

		default:
			break;
		}
	case Event::MouseButtonPressed:
	{
		soundSystem->EffectPlay("Click");
		break;
	}
	default:
		break;
	}
	}
	

}

void TitleScene::Destroy()
{

}

void TitleScene::Update(const float& deltaTime)
{
	if (mButtons["START"]->IsPressed())
	{	
		scenes->push(new TutorialScene(scenes, window, soundSystem));
	}
	else if (mButtons["EXIT"]->IsPressed())
	{
		scenes->top()->EndScene();
	}
	Scene::Update(deltaTime);
}

void TitleScene::Render(RenderWindow* window)
{
	Scene::Render(window);
}
