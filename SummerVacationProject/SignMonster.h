#pragma once
#include "Enemies.h"
class SignMonster : public Enemies
{
public:
	SignMonster();
	virtual ~SignMonster();

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Update(const float& deltaTime);

};
