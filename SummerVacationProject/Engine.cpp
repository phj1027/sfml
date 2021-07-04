#include "framework.h"
#include "Engine.h"

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

	this->window = new RenderWindow(VideoMode(500,500),"Window");
	// this�� ���� �ۼ��ϰ��ִ� Engine�� �ǹ��� == Engine�� window

	// ������â ������ �ٹ̱�
	Image icon;
	icon.loadFromFile("Textures/BMO_icon.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

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
		default:
			break;
		}
	}

	// keyBoardInput
	if (Keyboard::isKeyPressed(Keyboard::Escape)) // esc��ư �Է½� ������ â ����
	{
		window->close();
	}

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
	
	// �ð��� update�ؾ���
	deltaTime = timer.getElapsedTime().asSeconds();

	// input�� �������� ����Ǳ⶧���� update�� �Ϻκ�
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