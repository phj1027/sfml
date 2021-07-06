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
					// ��>Texture�� *�� �޾ұ⶧���� �������ؾ���
		++keyFrame;
		elapsedTime = 0.f;
		// ���� ��� clock.restart();�� ���� elapsedTime
	}
}
