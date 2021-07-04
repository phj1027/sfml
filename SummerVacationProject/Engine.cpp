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
