#include "framework.h"
#include "Enemies.h"

Enemies::Enemies()
{
	Init();
}

Enemies::~Enemies()
{

}

void Enemies::Init()
{

}

void Enemies::Destroy()
{
	AnimationObject::Destroy();
}

void Enemies::Update(const float& deltaTime)
{
	AnimationObject::Update(deltaTime);
}
