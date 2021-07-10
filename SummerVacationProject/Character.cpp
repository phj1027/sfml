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
		// ���� �����ϱ� ���� ��
		velocity.y += gravity;  // �����Ӹ��� �߷¿ø� -10 -> -8 -> -6 ....
	}
	else if (position.y > 200.f)
	{
		// �ٴ����� ������ ���� ���� ���� ��
		position.y = 200.f;
	}

	velocity += acceleration;
	position += velocity;

}

void Character::Update(const float& deltaTime)
{
	if (Keyboard::isKeyPressed(Keyboard::Space)) // ���� ����� ���� �ȵ� ��
	{
		// sfml ��ǥ�� �»�� (0,0) (���� �ö󰥼��� - �̰� �Ʒ��γ��������� + ������ + ���� -)
		state = JUMP;
		velocity.y = -10; // y��ӵ��� -10 ��
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