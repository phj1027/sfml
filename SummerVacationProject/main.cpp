#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(500, 500), "Window"); 

	// Sprite��������Ʈ : ������ ������ִ� ������Ʈ (���� ����� ����)
	// ��> scaling������� - texture����� �״�� �������⶧���� �̸� ����� ���ؼ� ������ ���� ���� 
	Sprite sp; 
	Texture tx; // texture�� ������ sprite�� �� 

	tx.loadFromFile("Textures/1.jpg"); // main.cpp ��ġ ���� �����

	sp.setScale(0.5f, 0.5f); // ������ ���� - �Ҽ��ϼ��� �۾����� 1�̻��� Ŀ���� ��
	sp.setTexture(tx); // sp�� texture���� 

	// �Ǻ� ��������Ʈ �߽����� �ٲ� 
	sp.setOrigin(tx.getSize().x / 2.f, tx.getSize().y / 2.f); // sp�� �����������⶧���� tx������ �̿��ؼ� �ٲ�
	sp.setPosition(250.f, 250.f); // ��ġ ����

	while (window.isOpen())
	{
		window.clear(); 

		window.draw(sp); // texture�� �ƴ� sprite�� �׸��°� 

		window.display();
	}
}
