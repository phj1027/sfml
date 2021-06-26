#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(500, 500), "Window"); // 500x500¥�� windowâ

	// �簢�� ������Ʈ rs
	RectangleShape rs;

	// vector2f = float�ڷ��� �ΰ�¥��(x,y) (*2.0�� double�ڷ��� 2.f�� float�ڷ���)
	rs.setSize(Vector2f(100.f, 100.f)); //������
	rs.setFillColor(Color::Green); // ����
	rs.setPosition(Vector2f(250.f, 250.f)); // ��ġ (*������Ʈ�� �Ǻ��� �»�� �����̱⶧���� ������ �Ѱ���� ��ġ��������)
	rs.setOrigin(rs.getSize() / 2.f); // ������Ʈ�� �Ǻ��� �»�ܿ��� ������Ʈ�� �Ѱ���� �Ű���

	while (window.isOpen())//�����찡 ���µǾ�������
	{
		window.clear(); // ������Ʈ�� �����϶� �� �����͵��� �ѹ��� ������

		rs.setPosition(rs.getPosition().x + .01f, rs.getPosition().y); //rs�� ������ġ���� x�������� 0.01f�� ������

		window.draw(rs); // rs�� �����쿡 �׷���

		window.display();// �����쿡 �׸� ������� ����ض�
	}
}
