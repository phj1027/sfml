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
	setPosition(Vector2f(250.f, 250.f));
	setOrigin(tx->getSize().x / 2.f, tx->getSize().y / 2.f);
}

void Character::Destroy()
{
	AnimationObject::Destroy();
}

void Character::Update(const float& deltaTime)
{

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		state = JUMP;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Z))
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

	if (elapsedTime > 0.1f)
	{
		//범위기반 for문
		// stateAnimation안에있는 객체들을 animation하나로 하나씩 불러올수있음 
		for (auto& animation : stateAnimation)
		{
			//first : 현재 스테이트  -> IDLE이냐 RUN이냐 JUMP냐 PUNCH냐 WALK냐 그소리 
			// animation -> <state(first), animationVector(second)>
			// <key,value> == <first,second> == <RUN,runanimation> ...
			if (animation.first == state) // first가 현재 state와 같다면 
			{
				setTexture(*animation.second.data()[keyFrame % animation.second.size()]);

				if (animation.first == PUNCH) // 스킬을 한번쓰면 원래상태로 돌아와야하니까 
				{
					// 애니메이션이 예를들어 IDLE같은경우 9개인데 1~9 다 돌았다면 == 애니메이션 하나가 끝났다면 ( 인덱스는 0번부터니까 -1해준것)
					// 사이즈는 그대로 
					if (keyFrame % animation.second.size() >= animation.second.size()-1)
					{
						state = IDLE;
					}
				}
				if (animation.first == JUMP) 
				{
					if (keyFrame % animation.second.size() >= animation.second.size()-1)
					{
						state = IDLE;
					}
				}
				if (animation.first != PUNCH || animation.first == PUNCH)
				{
					if (keyFrame % animation.second.size() >= animation.second.size()-1)
					{
						state = IDLE;
					}
				}
			}
		}
		
		++keyFrame;
		elapsedTime = 0.f;
		
	}
}