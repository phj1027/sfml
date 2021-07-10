#pragma once
#include "AnimationObject.h"

enum CHARACTER_STATE
{
	IDLE,
	WALK,
	RUN,
	JUMP,
	PUNCH
};

class Character : public AnimationObject
{
public:
	Character();
	virtual ~Character();

private:

	// 점프를 위한 물리적용
	Vector2f position{ 0.f,0.f };  // x좌표 y좌표 
	Vector2f velocity{ 0.f,0.f };  // x축 속도 y축 속도 
	Vector2f acceleration{ 0.f,0.f }; // x축가속도 y축가속도 

	float gravity = 5.f; // 중력

	//포인터로 쓰는 이유 그때그때 동적할당 해놓고 캐릭터가 사라질 시 여기서 풀어주면 되니까
	vector<Texture*> idleAnimation;
	vector<Texture*> walkAnimation;
	vector<Texture*> runAnimation;
	vector<Texture*> jumpAnimation;
	vector<Texture*> punchAnimation;

	int state = IDLE;

	//int자료형 하나랑 vector컨테이너 하나를 짝꿍시킴
	// ex) WALK하나 불렀다면 walkAnimation과 짝꿍
	// ex) RUN하나 불렀다면 runAnimation과 짝꿍
	map<int, vector<Texture*>> stateAnimation;
	// stateAnimation에서 키값(int자료형)을 불렀을때 해당 vector컨테이너가 튀어나오는것

private:
	virtual void Init();

public:
	virtual void Destroy();
	void MoveUpdate();
	virtual void Update(const float& deltaTime);
};

