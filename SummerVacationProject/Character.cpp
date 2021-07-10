#include "framework.h"
#include "Character.h"

Character::Character()
{
	Init();
}
Character::~Character()
{
}

void Character::Init()
{
	Texture* tx = nullptr;

	char filePath[150];
	for (int i = 0; i < 9; ++i)
	{
		sprintf(filePath, "Textures/Adventure Time with Finn and Jake/Finn&Jake/Finn&Jake_Idle_Calm1~9/Calm_(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->idleAnimation.push_back(tx);
	}
	for (int i = 0; i < 15; ++i)
	{
		sprintf(filePath, "Textures/Adventure Time with Finn and Jake/Finn&Jake/Finn&Jake_Walk1~16/Finn&Jake_Walk_(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->walkAnimation.push_back(tx);
	}
	for (int i = 0; i < 11; ++i)
	{
		sprintf(filePath, "Textures/Adventure Time with Finn and Jake/Finn&Jake/Finn&Jake_Run1~12/Finn&Jake_Run_(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->runAnimation.push_back(tx);
	}
	for (int i = 0; i < 17; ++i)
	{
		sprintf(filePath, "Textures/Adventure Time with Finn and Jake/Finn&Jake/Finn&Jake_Jump1~18/Jump (%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->jumpAnimation.push_back(tx);
	}
	for (int i = 0; i < 9; ++i)
	{
		sprintf(filePath, "Textures/Adventure Time with Finn and Jake/Finn&Jake/Finn&Jake_Punch1~10/punch(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->punchAnimation.push_back(tx);
	}

	stateAnimation[IDLE] = idleAnimation;
	stateAnimation[WALK] = walkAnimation;
	stateAnimation[RUN] = runAnimation;
	stateAnimation[JUMP] = jumpAnimation;
	stateAnimation[PUNCH] = punchAnimation;

	setScale(2.f, 2.f);
	setPosition(Vector2f(100.f, 100.f));
	
}

void Character::Destroy()
{
	AnimationObject::Destroy();
}

void Character::MoveUpdate()
{
	if (position.y < 200.f)
	{
		// 위로 점프하기 위한 것
		velocity.y += gravity;  // 프레임마다 중력올림 -10 -> -8 -> -6 ....
	}
	else if (position.y > 200.f)
	{
		// 바닥으로 꺼지는 것을 막기 위한 것
		position.y = 200.f;
	}

	velocity += acceleration;
	position += velocity;

}

void Character::Update(const float& deltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::Space)) // 점프 제대로 실행 안됨 ★
	{
		// sfml 좌표계 좌상단 (0,0) (위로 올라갈수록 - 이고 아래로내려갈수록 + 오른쪽 + 왼쪽 -)
		state = JUMP;
		velocity.y = -10; // y축속도를 -10 줌
	}

	MoveUpdate();
	setPosition(position);

	if (Keyboard::isKeyPressed(Keyboard::Z))
	{
		state = RUN;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		state = WALK;
	}
	else if (Keyboard::isKeyPressed(Keyboard::V))
	{
		keyFrame = 0;
		state = PUNCH;
	}

	// 다 if로 한다면 동시에 키 입력시 뒤의것만 실행됨 
	// else if로 하면 하나의 키만 입력받음 

	elapsedTime += deltaTime;

	if (elapsedTime > 0.05f)
	{
		 
		for (auto& animation : stateAnimation)
		{
			
			if (animation.first == state) // first가 현재 state와 같다면 
			{
				setTexture(*animation.second.data()[keyFrame % animation.second.size()]);

				if (animation.first == PUNCH) // 스킬을 한번쓰면 원래상태로 돌아와야하니까 
				{
					if (keyFrame % animation.second.size() >= animation.second.size()-1)
					{
						state = IDLE;
					}
				}
				if (animation.first != PUNCH)
				{
					if (keyFrame % animation.second.size() >= animation.second.size()-1)
					{
						state = IDLE;
						//punch가 아니면 꾹 눌러야만 애니메이션이 무한반복
						// 그렇다고 punch도 코드가 똑같은데 꾹누르면 무한반복되지않고 한애니메이션장면에 멈춰있음 왜지?★
					}
				}
			}
		}
		
		++keyFrame;
		elapsedTime = 0.f;
		
	}
}