#include "framework.h"
#include "SignMonster.h"

SignMonster::SignMonster()
{
	Init();
}

SignMonster::~SignMonster()
{

}

void SignMonster::Init()
{
	Texture* tx = nullptr;

	char filePath[150];
	for (int i = 1; i < 8; ++i)
	{
		sprintf(filePath, "Textures/Adventure Time with Finn and Jake/Enemies/SignMonster/SignMonster_Walk1~8/SignMonster_Walk_(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}
	setScale(2.f, 2.f);
	setPosition(Vector2f(500.f, 250.f));
	setOrigin(tx->getSize().x / 2.f, tx->getSize().y / 2.f);
}

void SignMonster::Destroy()
{
	Enemies::Destroy();
}

void SignMonster::Update(const float& deltaTime)
{
	Enemies::Update(deltaTime);
}
