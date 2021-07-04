#define _CRT_SECURE_NO_WARNINGS
#include "framework.h"
#include "AnimationObject.h"

AnimationObject::AnimationObject()
{
	Init();
}

AnimationObject::~AnimationObject()
{
}

void AnimationObject::Init()
{
	Texture* tx = nullptr;

	char filePath[150];
	for (int i = 1; i < 27; ++i)
	{
		sprintf(filePath, "Textures/Adventure Time with Finn and Jake/Finn&Jake/Finn&Jake_Idle_Eyes1~27/Finn&Jake_Idle_Eyes_(%d).png", i);
		tx = new Texture;
		tx->loadFromFile(filePath);
		this->vAnimation.push_back(tx);
	}

	setScale(2.f,2.f); 
	setPosition(Vector2f(250.f, 250.f));
	setOrigin(tx->getSize().x / 2.f, tx->getSize().y / 2.f);
}

void AnimationObject::Destroy()
{
}

void AnimationObject::Update(const float& deltaTime)
{
	elapsedTime += deltaTime;

	if (elapsedTime > 0.1f)
	{
		setTexture(*vAnimation.data()[keyFrame % vAnimation.size()]);
					// ㄴ>Texture를 *로 받았기때문에 역참조해야함
		++keyFrame;
		elapsedTime = 0.f;
		// 전에 썼던 clock.restart();는 못씀 elapsedTime
	}
}
