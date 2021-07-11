#include "framework.h"
#include "LobbyScene.h"
#include "BackGroundObject.h"

LobbyScene::LobbyScene()
{
	Init();
}

LobbyScene::LobbyScene(stack<Scene*>* scenes) : Scene(scenes)
{
	Init();
}

LobbyScene::~LobbyScene()
{
}

void LobbyScene::Init()
{
	
	Font* font = new Font;
	font->loadFromFile("Font/CookieRun_Bold.ttf");
	Text* text = new Text("Press D Keys", *font);
	text->setFillColor(Color::White);
	text->setOrigin(text->getGlobalBounds().width / 2.f, text->getGlobalBounds().height / 2.f);
	text->setPosition(Vector2f(1000 / 2.f, 550.f));
	mTexts["TEST"] = text;
}

void LobbyScene::Destroy()
{

}

void LobbyScene::Update(const float& deltaTime)
{
	static float elapsedTime = 0.f;

	static float txtScale = 1.f; // 초기값이 1임

	static int frame = 0;
	static int div = 1;

	if ((elapsedTime += deltaTime) >= 0.03f)
	{
		if ((++frame % 30) == 0)
		{
			div *= -1;
		}
		txtScale +=( 0.01f*div);
		mTexts["TEST"]->setScale(Vector2f(txtScale, txtScale));
		elapsedTime = 0.f;
	}

	Scene::Update(deltaTime);
}

void LobbyScene::Render(RenderWindow* window)
{

	Scene::Render(window);
}
