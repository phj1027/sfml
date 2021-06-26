#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(500, 500), "Window"); 

	window.setFramerateLimit(60); // 6���������� ���� �ʹ������� �̰��ϱ�

	IntRect txSq(0, 0, 319 / 3, 424 / 4);  // texture �ڸ� �� �ִ� ������
		// rectLaft(�ǿ���) , rectTop(����), rectWidth(�ǿ��ʿ��������� ����), rectHeight(���������� ����)

	Texture tx;
	tx.loadFromFile("Textures/DragonFrames.png"); // 319x424 ũ���� ���� 

	Sprite sp(tx, txSq); // sprite�����ڿ� tx,txSq�� ��
	sp.setScale(3.f, 3.f); // 3��

	Clock clock; // �ð���� �Լ� �ð������ϴ� class

	while (window.isOpen())
	{
		window.clear();

		Event e;
		while (window.pollEvent(e)) // ����ؼ� �����쿡 ���� �̺�Ʈ�� ����
		// �̺�Ʈ�� ���������� ���� 
		{
			switch (e.type) //�̺�ƮŸ�Թ���
			{
			case Event::Closed: // ������ݴ� closed��
			{
				window.close(); // �̰��ϰԵǸ� �� ����isopen�� false�Ǹ鼭 while�����������鼭 ��������
				//���� â�� x��ư ������ �� �� ���� 
				break;
			}
			default:
				break;
			}
		}
		if (clock.getElapsedTime().asSeconds() >= 0.3f) 
		// clock�� ����ɶ����� ����ؼ� �ð��� �þ �ٵ� 0.3�ʰ��Ǿ����� if������
		{
			if (txSq.left >= 318 - 106) 
			// �� ������ �ؽ��� left�� �ٴٶ��ٸ� �ٽ� �� ù��° �ؽ���(���� left�� 0�̴ϱ�)�� ���� left�� 0���� �ʱ�ȭ 
			{
				txSq.left = 0; 
			}
			else
			// ���� �� ������ �ؽ��Ŀ� ���������ʾҴٸ� ���� �ؽ��ķ� ���� left ��ǥ�� �÷��� 
			{
				txSq.left += 319 / 3;
			}

			sp.setTextureRect(txSq); // txSq�� ���� �簢�� ���� sp���� �Ѱ��� �׸�ŭ �߶� tx������
			clock.restart(); // 0.3�� �Ǿ��ٸ� �ٽ� 0�ʷ� �ʱ�ȭ �� ����� 
		}
		window.draw(sp);
		window.display();
	}
}
