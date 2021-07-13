#pragma once
#include "Object.h"
class Button : public Object
{
public:
	Button();
	Button(const string& idleTexturePath, const string& activeTexturePath, const Vector2f& position);
					// 마우스 클릭안했을떄				// 마우스 클릭했을때					// 좌표  
	virtual ~Button();

private:

	Texture* idleTexture = nullptr;
	Texture* activeTexture = nullptr;

	bool isPressed = false; // 버튼이 눌렸니?

private:

	virtual void Init();
	virtual void Init(const string& idleTexturePath, const string& activeTexturePath, const Vector2f& position);

public:

	virtual void Destroy();

	bool IsPressed();

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);
};
