#include "framework.h"
#include "Engine.h"
#include "EnemiesScene.h"
#include "CharacterScene.h"
#include "TitleScene.h"
#include "LobbyScene.h"

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

	this->window = new RenderWindow(VideoMode(1000,600),"Adventure Time with Finn and Jake");
	// this는 현재 작성하고있는 Engine을 의미함 == Engine의 window

	window->setMouseCursorVisible(true); // 마우스 커서 보이게 설정

	// 윈도우창 아이콘 꾸미기
	Image icon;
	icon.loadFromFile("Textures/Cinnamon_Bun_icon.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	this->scenes.push(new TitleScene(&scenes)); // 아무것도 없는 첫 장면 == titlescene
	cout << "Title Scene\n";
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
				this->scenes.push(new CharacterScene); // 캐릭터 scene으로 감
				cout << "Character Scene\n";
				break;
			}
			case Keyboard::S: // S 입력받았다면
			{
				this->scenes.push(new EnemiesScene); // Enemiesq scene으로 감
				cout << "Enemies Scene\n";
				break;
			}
			case Keyboard::D: 
			{
				this->scenes.push(new LobbyScene);
				cout << "Lobby Scene\n";
				break;
			}
			case Keyboard::Q:
			{
				scenes.top()->EndScene();
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
	//if (Mouse::isButtonPressed(Mouse::Left))
	//{
	//	window->setTitle("Left Click");
	//}
	//else if (Mouse::isButtonPressed(Mouse::Right))
	//{
	//	window->setTitle("Right Click");
	//}
	//else
	//{
	//	window->setTitle("Adventure Time with Finn and Jake");
	//}
}

void Engine::Update()
{
	// 시간도 update해야함
	deltaTime = timer.getElapsedTime().asSeconds();

	
	timer.restart();

	// input은 매프레임 실행되기때문에 update의 일부분
	Input();

	if (!scenes.empty()) // scenes가 비어있지않다면 실행해라 
	{
		scenes.top()->Update(deltaTime); // 맨위에있는 것을 업데이트 
		
		if (this->scenes.top()->GetQuit()) // 현재 실행중인 scene을 종료한다.
		{
			delete this->scenes.top();
			this->scenes.pop();
			cout << "Pop Scene\n";
		}
	}
	else // 씬이 없으면 엔진만 살아있고 장면이 없기 때문에 게임 종료하기 
	{
		window->close();
	}
}

void Engine::Render()
{
	while (window->isOpen())
	{
		window->clear();
		Update();

		if (!scenes.empty()) // scenes가 비어있지않다면 실행해라 
		{
			scenes.top()->Render(window);  // 맨위에있는 것을 랜더링
		}
	
		window->display();
	}
}
