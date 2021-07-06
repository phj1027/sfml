#include "framework.h"
#include "BigZombie.h"

BigZombie::BigZombie()
{
	Init();
}

BigZombie::~BigZombie()
{

}

void BigZombie::Init()
{
	Texture* tx = nullptr;

	char filePath[150];
	for (int i = 1; i < 10; ++i)
	{
		sprintf(filePath, "Textures/Adventure Time with Finn and Jake/Enemies/BigZombie/BigZombie_Walk1~10/BigZombie_Walk_(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}
	setScale(2.f, 2.f);
	setPosition(Vector2f(100.f, 250.f));
	setOrigin(tx->getSize().x / 2.f, tx->getSize().y / 2.f);
}

void BigZombie::Destroy()
{
	Enemies::Destroy();
}

void BigZombie::Update(const float& deltaTime)
{
	Enemies::Update(deltaTime);
}
