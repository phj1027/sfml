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
	for (int i = 1; i < 16; ++i)
	{
		sprintf(filePath, "Textures/Adventure Time with Finn and Jake/Finn&Jake/Finn&Jake_Walk1~16/Finn&Jake_Walk_(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}

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
	AnimationObject::Update(deltaTime);
}