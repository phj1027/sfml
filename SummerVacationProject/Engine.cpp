#include "framework.h"
#include "Engine.h"

Engine::Engine()
{
	Init(); // 생성되었을때 바로 초기화 
}

Engine::~Engine()
{

}

void Engine::Init()
{
	// 현재 window 변수는 포인터로 존재함

	this->window = new RenderWindow(VideoMode(500,500),"Window");
	// this는 현재 작성하고있는 Engine을 의미함 == Engine의 window

	// 윈도우창 아이콘 꾸미기
	Image icon;
	icon.loadFromFile("Textures/BMO_icon.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	// 여러 set기능들 살펴보기
	window->setMouseCursorVisible(true); // 마우스커서 보이게 하는 법 - false로 하면 커서 숨길 수 있음

}

void Engine::Destroy()
{
	// Init에서 window는 new로 동적할당을 받았기 때문에 풀어줘야함
	// window가 nullptr이 아니라면
	if (window)
	{
		delete window;
	}
}

void Engine::Input()
{
	// 이벤트는 외부로부터 이벤트를 받는거니까 input 
	while (window->pollEvent(evt))
	{
		switch (evt.type)
		{
		case Event::Closed:
		{
			window->close();
			break;
		}
		default:
			break;
		}
	}
}

void Engine::Update()
{
	
	// 시간도 update해야함
	deltaTime = timer.getElapsedTime().asSeconds();

	// input은 매프레임 실행되기때문에 update의 일부분
	Input();
}

void Engine::Render()
{

	while (window->isOpen())
	{
		window->clear();
		Update();
		window->display();
	}
}
