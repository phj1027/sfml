#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(500, 500), "Window"); 

	// Sprite스프라이트 : 사진을 덮어쓸수있는 오브젝트 (절대 사이즈가 없음)
	// ㄴ> scaling해줘야함 - texture사이즈를 그대로 가져오기때문에 이를 배수를 곱해서 사이즈 변경 가능 
	Sprite sp; 
	Texture tx; // texture를 입히면 sprite가 됨 

	tx.loadFromFile("Textures/1.jpg"); // main.cpp 위치 기준 상대경로

	sp.setScale(0.5f, 0.5f); // 사이즈 조절 - 소수일수록 작아지고 1이상은 커지는 것
	sp.setTexture(tx); // sp에 texture입힘 

	// 피봇 스프라이트 중심으로 바꿈 
	sp.setOrigin(tx.getSize().x / 2.f, tx.getSize().y / 2.f); // sp는 절대사이즈없기때문에 tx사이즈 이용해서 바꿈
	sp.setPosition(250.f, 250.f); // 위치 설정

	while (window.isOpen())
	{
		window.clear(); 

		window.draw(sp); // texture가 아닌 sprite를 그리는것 

		window.display();
	}
}
