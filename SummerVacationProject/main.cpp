#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(500, 500), "Window"); // 500x500짜리 window창

	// 사각형 오브젝트 rs
	RectangleShape rs;

	// vector2f = float자료형 두개짜리(x,y) (*2.0은 double자료형 2.f는 float자료형)
	rs.setSize(Vector2f(100.f, 100.f)); //사이즈
	rs.setFillColor(Color::Green); // 색상
	rs.setPosition(Vector2f(250.f, 250.f)); // 위치 (*오브젝트의 피봇이 좌상단 기준이기때문에 윈도우 한가운데에 위치하지않음)
	rs.setOrigin(rs.getSize() / 2.f); // 오브젝트의 피봇을 좌상단에서 오브젝트의 한가운데로 옮겨줌

	while (window.isOpen())//윈도우가 오픈되어잇을때
	{
		window.clear(); // 오브젝트를 움직일때 그 전에것들을 한번씩 지워줌

		rs.setPosition(rs.getPosition().x + .01f, rs.getPosition().y); //rs를 현재위치에서 x방향으로 0.01f씩 움직임

		window.draw(rs); // rs를 윈도우에 그려라

		window.display();// 윈도우에 그린 결과물을 출력해라
	}
}
