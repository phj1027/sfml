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

	//idleTexture에 대한 크기를 가지고 setOrigin
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
	isPressed = false; // 처음 상태는 idle상태여야하니까 

	if (getGlobalBounds().contains(mousePosition)) // 이 오브젝트의 범위(크기,좌표같은 정보)에 mousePosition을 포함하고있다면 == 마우스포지션이 글로벌바운드에 들어가있고
	{
		if (Mouse::isButtonPressed(Mouse::Left)) // 그 범위안에 들어가있을때 마우스 왼쪽버튼 클릭했다면
		{
			isPressed = true;
		}
	}

	if (isPressed) // 버튼 눌렸다면 active , 아니라면 idle
	{
		setTexture(*activeTexture);
	}
	else
	{
		setTexture(*idleTexture);
	}

}