#pragma once
#include "Enemies.h"
class BigZombie : public Enemies
{
public:
	BigZombie();
	virtual ~BigZombie();

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Update(const float& deltaTime);

};
