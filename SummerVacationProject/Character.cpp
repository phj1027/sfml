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

	// �� if�� �Ѵٸ� ���ÿ� Ű �Է½� ���ǰ͸� ����� 
	// else if�� �ϸ� �ϳ��� Ű�� �Է¹��� 

	elapsedTime += deltaTime;

	if (elapsedTime > 0.1f)
	{
		//������� for��
		// stateAnimation�ȿ��ִ� ��ü���� animation�ϳ��� �ϳ��� �ҷ��ü����� 
		for (auto& animation : stateAnimation)
		{
			//first : ���� ������Ʈ  -> IDLE�̳� RUN�̳� JUMP�� PUNCH�� WALK�� �׼Ҹ� 
			// animation -> <state(first), animationVector(second)>
			// <key,value> == <first,second> == <RUN,runanimation> ...
			if (animation.first == state) // first�� ���� state�� ���ٸ� 
			{
				setTexture(*animation.second.data()[keyFrame % animation.second.size()]);

				if (animation.first == PUNCH) // ��ų�� �ѹ����� �������·� ���ƿ;��ϴϱ� 
				{
					// �ִϸ��̼��� ������� IDLE������� 9���ε� 1~9 �� ���Ҵٸ� == �ִϸ��̼� �ϳ��� �����ٸ� ( �ε����� 0�����ʹϱ� -1���ذ�)
					// ������� �״�� 
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