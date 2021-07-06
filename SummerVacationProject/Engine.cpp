#include "framework.h"
#include "Engine.h"
#include "Character.h"
#include "SignMonster.h"
#include "BigZombie.h"

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

	obj.push_back(new Character);
	obj.push_back(new SignMonster);
	obj.push_back(new BigZombie);
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
	if (Keyboard::isKeyPressed(Keyboard::Escape)) // esc��ư �Է½� ������ â ����
	{
		window->close();
	}
	//else if (Keyboard::isKeyPressed(Keyboard::A)) // �����Ӹ��� ��� �����ִ��� Ȯ�� -> �ǽð����� �̵��Ҷ� Ȱ��
	//{
	//	cout << "Pressed A key!!\n"; //1�ʿ� ��������Ӿ� �����̱⶧���� �ѹ��� �Է��ص� ������ ��µ�
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
		window->setTitle("Adventure Time with Finn and Jake");
	}
}

void Engine::Update()
{
	// �ð��� update�ؾ���
	deltaTime = timer.getElapsedTime().asSeconds();

	for (auto& o : obj)
	{
		o->Update(deltaTime);
	}

	timer.restart();

	// input�� �������� ����Ǳ⶧���� update�� �Ϻκ�
	Input();
}

void Engine::Render()
{
	while (window->isOpen())
	{
		window->clear();
		Update();

		for (auto& o : obj)
		{
			window->draw(*o);
		}
		
		window->display();
	}
}
