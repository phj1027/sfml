#include "framework.h"
#include "Engine.h"
#include "TitleScene.h"

Engine::Engine()
{
	Init(); // �����Ǿ����� �ٷ� �ʱ�ȭ 
}

Engine::~Engine()
{
	Destroy();
}

void Engine::Init()
{
	// ���� window ������ �����ͷ� ������
	this->window = new RenderWindow(VideoMode(1300,700),"Adventure Time with Finn and Jake");
	// this�� ���� �ۼ��ϰ��ִ� Engine�� �ǹ��� == Engine�� window

	this->window->setMouseCursorVisible(true); // ���콺 Ŀ�� ���̰� ����

	this->evt = new Event;
	this->timer = new Clock;

	soundSystem = new SoundSystem("Sound/happybgm.wav", true);

	soundSystem->Play();

	// ������â ������ �ٹ̱�
	Image icon;
	icon.loadFromFile("Textures/Jake_Forms.png");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	scenes.push(new TitleScene(&scenes, window, soundSystem)); // �ƹ��͵� ���� ù ��� == titlescene == ���۾�
	cout << "Title Scene\n";
}

void Engine::Destroy()
{
	DELETE(timer);
	DELETE(evt);
	DELETE(window);

	soundSystem->Destroy(); //AL lib: (EE) alc_cleanup: 1 device not closed �ذ�
}

void Engine::Input()
{
	// �̺�Ʈ�� �ܺηκ��� �̺�Ʈ�� �޴°Ŵϱ� input 
	while (window->pollEvent(*evt))
	{
		switch (evt->type)
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
				scenes.top()->Input(&*evt);
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
	deltaTime = timer->getElapsedTime().asSeconds();

	
	timer->restart();

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
