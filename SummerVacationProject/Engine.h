#pragma once

// 게임 전체를 이르는 클래스 - 게임 런처,클라이언트 같은것 이거없으면 실행이 되지않음

class Engine final // final : 더이상 이 클레스에게 상속받지 않는다.
{

public: // 생성자, 소멸자

	Engine();
	~Engine();

private: // 멤버 변수

	// 오브젝트들을 그리기위한 윈도우를 생성
	RenderWindow* window = nullptr;
	Event evt;

	// 게임 전체에 대한 시간
	Clock timer;
	float deltaTime = 0.f; // 엔진에서 deltaTime가지고 모든 오브젝트를 시간에 맞게 정해줄것

private: // 메소드

	// 엔진을 초기화 하는 함수
	void Init();

	// 현재 살아있는 오브젝트를 업데이트한다.
	void Update();

	// 윈도우 상의 입력값을 처리한다.
	void Input();

public:

	// 윈도우에 결과물을 출력한다.
	void Render();

	// 엔진이 없어지기전에 호출되는 함수
	void Destroy();


};

