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
	
}

void AnimationObject::Destroy()
{
	for (auto& i : vAnimation)
	{
		delete i;
	}
	
	vAnimation.clear();
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
