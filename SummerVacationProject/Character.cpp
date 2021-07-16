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
	
	setScale(3.5f, 3.5f);
	setPosition(Vector2f(20.f, 480.f));

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
		this->rightwalkAnimation.push_back(tx);
	}
	for (int i = 16; i < 31; ++i)
	{
		sprintf(filePath, "Textures/Adventure Time with Finn and Jake/Finn&Jake/Finn&Jake_Walk1~16/Finn&Jake_Walk_(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->leftwalkAnimation.push_back(tx);
	}
	for (int i = 0; i < 11; ++i)
	{
		sprintf(filePath, "Textures/Adventure Time with Finn and Jake/Finn&Jake/Finn&Jake_Run1~12/Finn&Jake_Run_(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->rightrunAnimation.push_back(tx);
	}
	for (int i = 12; i < 23; ++i)
	{
		sprintf(filePath, "Textures/Adventure Time with Finn and Jake/Finn&Jake/Finn&Jake_Run1~12/Finn&Jake_Run_(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->leftrunAnimation.push_back(tx);
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
	stateAnimation[RIGHTWALK] = rightwalkAnimation;
	stateAnimation[LEFTWALK] = leftwalkAnimation;
	stateAnimation[RIGHTRUN] = rightrunAnimation;
	stateAnimation[LEFTRUN] = leftrunAnimation;
	stateAnimation[JUMP] = jumpAnimation;
	stateAnimation[PUNCH] = punchAnimation;


}

void Character::Destroy()
{
	AnimationObject::Destroy();
}

void Character::MoveUpdate()
{

}

void Character::Update(const float& deltaTime)
{

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		state = RIGHTRUN;
		move(0.1f, 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		state = LEFTRUN;
		move(-0.1f, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		state = RIGHTWALK;
		move(0.07f, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		state = LEFTWALK;
		move(-0.07f, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::V))
	{
		keyFrame = 0;
		state = PUNCH;
	}

	// �� if�� �Ѵٸ� ���ÿ� Ű �Է½� ���ǰ͸� ����� 
	// else if�� �ϸ� �ϳ��� Ű�� �Է¹��� 

	elapsedTime += deltaTime;

	if (elapsedTime > 0.05f)
	{
		 
		for (auto& animation : stateAnimation)
		{
			
			if (animation.first == state) // first�� ���� state�� ���ٸ� 
			{
				setTexture(*animation.second.data()[keyFrame % animation.second.size()]);

				if (animation.first == PUNCH) // ��ų�� �ѹ����� �������·� ���ƿ;��ϴϱ� 
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
						//punch�� �ƴϸ� �� �����߸� �ִϸ��̼��� ���ѹݺ�
						// �׷��ٰ� punch�� �ڵ尡 �Ȱ����� �ڴ����� ���ѹݺ������ʰ� �Ѿִϸ��̼���鿡 �������� ����?��
					}
				}
			}
		}
		
		++keyFrame;
		elapsedTime = 0.f;
		
	}
}