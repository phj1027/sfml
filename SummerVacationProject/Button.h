#pragma once
#include "Object.h"
class Button : public Object
{
public:
	Button();
	Button(const string& idleTexturePath, const string& activeTexturePath, const Vector2f& position);
					// ���콺 Ŭ����������				// ���콺 Ŭ��������					// ��ǥ  
	virtual ~Button();

private:

	Texture* idleTexture = nullptr;
	Texture* activeTexture = nullptr;

	bool isPressed = false; // ��ư�� ���ȴ�?

private:

	virtual void Init();
	virtual void Init(const string& idleTexturePath, const string& activeTexturePath, const Vector2f& position);

public:

	virtual void Destroy();

	bool IsPressed();

	virtual void Update(const float& deltaTime);
	virtual void Update(const Vector2f& mousePosition);
};
