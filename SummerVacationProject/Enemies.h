#pragma once
#include "AnimationObject.h"

class Enemies : public AnimationObject
{
public:
	Enemies();
	virtual ~Enemies();

private:
	virtual void Init();

public:
	virtual void Destroy();
	virtual void Update(const float& deltaTime);
			
};


