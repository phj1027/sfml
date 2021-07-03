#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{
	RenderWindow window(VideoMode(500, 500), "Window");

	vector<Texture> txVector;

	Texture tx;
	char name[150];

	for (int i = 1; i <= 12; ++i)
	{
		sprintf(name, "Textures/Adventure Time with Finn and Jake/Finn&Jake/Finn&Jake_idle_1~12/Finn & Jake_Idle_00%d.png", i);
		// cout << name << endl; // 관찰위한 코드 
		tx.loadFromFile(name);
		txVector.push_back(tx);
	}

	Sprite sp;
	sp.setScale(3.f, 3.f); // 사이즈

	sp.setOrigin(tx.getSize().x / 2.f, tx.getSize().y / 2.f);
	sp.setPosition(Vector2f(250.f, 250.f)); // 좌상단이 0,0 기준으로 위치설정

	Clock clock;

	size_t keyFrameTime = 0;  

	while (window.isOpen())
	{
		window.clear();

		Event e;
		while (window.pollEvent(e)) 
		{
			switch (e.type) 
			{
			case Event::Closed:
			{
				window.close(); 
				break;
			}
			default:
				break;
			}
		}

		if (clock.getElapsedTime().asSeconds() > 0.2f)
		{
			sp.setTexture(txVector.data()[++keyFrameTime % txVector.size()]);
			clock.restart();
		}

		window.draw(sp);
		window.display();
	}
}