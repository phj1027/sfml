#include "framework.h"
#include "Button.h"

Button::Button()
{
	Init();
}

Button::Button(const string& idleTexturePath, const string& activeTexturePath, const Vector2f& position)
{
	Init(idleTexturePath, activeTexturePath, position);
}

Button::~Button()
{
}

void Button::Init()
{
}

void Button::Init(const string& idleTexturePath, const string& activeTexturePath, const Vector2f& position)
{
	idleTexture = new Texture;
	idleTexture->loadFromFile(idleTexturePath);

	activeTexture = new Texture;
	activeTexture->loadFromFile(activeTexturePath);

	setTexture(*idleTexture);

	//idleTexture�� ���� ũ�⸦ ������ setOrigin
	setOrigin(idleTexture->getSize().x / 2.f, idleTexture->getSize().y / 2.f);

	setPosition(position);

}

void Button::Destroy()
{
}

bool Button::IsPressed()
{
	return isPressed;
}

void Button::Update(const float& deltaTime)
{
}

void Button::Update(const Vector2f& mousePosition)
{
	isPressed = false; // ó�� ���´� idle���¿����ϴϱ� 

	if (getGlobalBounds().contains(mousePosition)) // �� ������Ʈ�� ����(ũ��,��ǥ���� ����)�� mousePosition�� �����ϰ��ִٸ� == ���콺�������� �۷ι��ٿ�忡 ���ְ�
	{
		if (Mouse::isButtonPressed(Mouse::Left)) // �� �����ȿ� �������� ���콺 ���ʹ�ư Ŭ���ߴٸ�
		{
			isPressed = true;
		}
	}

	if (isPressed) // ��ư ���ȴٸ� active , �ƴ϶�� idle
	{
		setTexture(*activeTexture);
	}
	else
	{
		setTexture(*idleTexture);
	}

}