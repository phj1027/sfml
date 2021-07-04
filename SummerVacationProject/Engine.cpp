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
		// 키보드 이벤트
		case Event::KeyPressed: // 한번입력할때 한번실행 -> 스킬쓸때 활용
		{
			switch (evt.key.code)
			{
			case Keyboard::A: // A 입력받았다면
			{
				cout << "Pressed A key!!\n";
				break;
			}
			default:
				break;
			}
		}
		default:
			break;
		}
	}

	// keyBoardInput
	if (Keyboard::isKeyPressed(Keyboard::Escape)) // esc버튼 입력시 윈도우 창 닫힘
	{
		window->close();
	}
	//else if (Keyboard::isKeyPressed(Keyboard::A)) // 프레임마다 계속 눌려있는지 확인 -> 실시간으로 이동할때 활용
	//{
	//	cout << "Pressed A key!!\n"; //1초에 몇십프레임씩 움직이기때문에 한번만 입력해도 여러번 출력됨
	//}


	// Mouse Input
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		window->setTitle("Left Click");
	}
	else if (Mouse::isButtonPressed(Mouse::Right))
	{
		window->setTitle("Right Click");
	}
	else
	{
		window->setTitle("Window");
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
