#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(500, 500), "Window"); 

	window.setFramerateLimit(60); // 6프레임으로 고정 너무빠르면 이거하기

	IntRect txSq(0, 0, 319 / 3, 424 / 4);  // texture 자를 수 있는 생성자
		// rectLaft(맨왼쪽) , rectTop(맨위), rectWidth(맨왼쪽에서부터의 길이), rectHeight(맨위부터의 높이)

	Texture tx;
	tx.loadFromFile("Textures/DragonFrames.png"); // 319x424 크기의 사진 

	Sprite sp(tx, txSq); // sprite생성자에 tx,txSq를 줌
	sp.setScale(3.f, 3.f); // 3배

	Clock clock; // 시간재는 함수 시간관리하는 class

	while (window.isOpen())
	{
		window.clear();

		Event e;
		while (window.pollEvent(e)) // 계속해서 윈도우에 대한 이벤트를 받음
		// 이벤트가 들어왔을때만 실행 
		{
			switch (e.type) //이벤트타입뭐냐
			{
			case Event::Closed: // 윈도우닫는 closed임
			{
				window.close(); // 이거하게되면 맨 위의isopen이 false되면서 while문빠져나오면서 게임종료
				//이제 창의 x버튼 눌러서 끌 수 있음 
				break;
			}
			default:
				break;
			}
		}
		if (clock.getElapsedTime().asSeconds() >= 0.3f) 
		// clock은 실행될때부터 계속해서 시간이 늘어나 근데 0.3초가되었으면 if문실행
		{
			if (txSq.left >= 318 - 106) 
			// 맨 마지막 텍스쳐 left에 다다랐다면 다시 맨 첫번째 텍스쳐(얘의 left는 0이니까)로 가게 left를 0으로 초기화 
			{
				txSq.left = 0; 
			}
			else
			// 아직 맨 마지막 텍스쳐에 도달하지않았다면 다음 텍스쳐로 가게 left 좌표를 늘려줌 
			{
				txSq.left += 319 / 3;
			}

			sp.setTextureRect(txSq); // txSq로 정한 사각형 범위 sp한테 넘겨줌 그만큼 잘라서 tx쓰란것
			clock.restart(); // 0.3초 되었다면 다시 0초로 초기화 후 재시작 
		}
		window.draw(sp);
		window.display();
	}
}
