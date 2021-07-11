#include "framework.h"
#include "Engine.h"
#include "EnemiesScene.h"
#include "CharacterScene.h"
#include "TitleScene.h"
#include "LobbyScene.h"

Engine::Engine()
{
	Init(); // �����Ǿ����� �ٷ� �ʱ�ȭ 
}

Engine::~Engine()
{

}

void Engine::Init()
{
	// ���� window ������ �����ͷ� ������

	this->window = new RenderWindow(VideoMode(1000,600),"Adventure Time with Finn and Jake");
	// this�� ���� �ۼ��ϰ��ִ� Engine�� �ǹ��� == Engine�� window

	window->setMouseCursorVisible(true); // ���콺 Ŀ�� ���̰� ����

	// ������â ������ �ٹ̱�
	Image icon;
	icon.loadFromFile("Textures/Cinnamon_Bun_icon.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	this->scenes.push(new TitleScene(&scenes)); // �ƹ��͵� ���� ù ��� == titlescene
	cout << "Title Scene\n";
}

void Engine::Destroy()
{
	// Init���� window�� new�� �����Ҵ��� �޾ұ� ������ Ǯ�������
	// window�� nullptr�� �ƴ϶��
	if (window)
	{
		delete window;
	}
}

void Engine::Input()
{
	// �̺�Ʈ�� �ܺηκ��� �̺�Ʈ�� �޴°Ŵϱ� input 
	while (window->pollEvent(evt))
	{
		switch (evt.type)
		{
		case Event::Closed:
		{
			window->close();
			break;
		}
		// Ű���� �̺�Ʈ
		case Event::KeyPressed: // �ѹ��Է��Ҷ� �ѹ����� -> ��ų���� Ȱ��
		{
			switch (evt.key.code)
			{
			case Keyboard::A: // A �Է¹޾Ҵٸ�
			{
				this->scenes.push(new CharacterScene); // ĳ���� scene���� ��
				cout << "Character Scene\n";
				break;
			}
			case Keyboard::S: // S �Է¹޾Ҵٸ�
			{
				this->scenes.push(new EnemiesScene); // Enemiesq scene���� ��
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
	if (Keyboard::isKeyPressed(Keyboard::Escape)) // esc��ư �Է½� ������ â ����
	{
		window->close();
	}
	//else if (Keyboard::isKeyPressed(Keyboard::A)) // �����Ӹ��� ��� �����ִ��� Ȯ�� -> �ǽð����� �̵��Ҷ� Ȱ��
	//{
	//	cout << "Pressed A key!!\n"; //1�ʿ� ��������Ӿ� �����̱⶧���� �ѹ��� �Է��ص� ������ ��µ�
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
	// �ð��� update�ؾ���
	deltaTime = timer.getElapsedTime().asSeconds();

	
	timer.restart();

	// input�� �������� ����Ǳ⶧���� update�� �Ϻκ�
	Input();

	if (!scenes.empty()) // scenes�� ��������ʴٸ� �����ض� 
	{
		scenes.top()->Update(deltaTime); // �������ִ� ���� ������Ʈ 
		
		if (this->scenes.top()->GetQuit()) // ���� �������� scene�� �����Ѵ�.
		{
			delete this->scenes.top();
			this->scenes.pop();
			cout << "Pop Scene\n";
		}
	}
	else // ���� ������ ������ ����ְ� ����� ���� ������ ���� �����ϱ� 
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

		if (!scenes.empty()) // scenes�� ��������ʴٸ� �����ض� 
		{
			scenes.top()->Render(window);  // �������ִ� ���� ������
		}
	
		window->display();
	}
}
