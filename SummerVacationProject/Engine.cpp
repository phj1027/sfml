#include "framework.h"
#include "Engine.h"
#include "TitleScene.h"

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
	this->window = new RenderWindow(VideoMode(1300,600),"Adventure Time with Finn and Jake");
	// this�� ���� �ۼ��ϰ��ִ� Engine�� �ǹ��� == Engine�� window

	window->setMouseCursorVisible(true); // ���콺 Ŀ�� ���̰� ����

	// ������â ������ �ٹ̱�
	Image icon;
	icon.loadFromFile("Textures/Jake_Forms.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	this->scenes.push(new TitleScene(&scenes)); // �ƹ��͵� ���� ù ��� == titlescene == ���۾�
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
			if (!scenes.empty())
			{
				scenes.top()->Input(&evt);
			}
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
