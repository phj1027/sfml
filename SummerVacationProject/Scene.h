#pragma once
#include "BackGroundObject.h"
#include "Button.h"

class Object; // vector<Object*> vObjects;�� �������� 

class Scene // Scene�� ��ӹ޴� �ֵ��� ���� _ ���� ���� Ŭ������ ����°�
{
public:
	Scene();
	Scene(stack<Scene*>* scenes, RenderWindow* window); // ������ �����츦 �������ְ��� ��������´�� �������ִ´��
	virtual ~Scene();

protected:

	// �ִϸ��̼��� �Ǵ� ������Ʈ �����̳�
	vector<Object*> animationObjects;
	// �ִϸ��̼��� ���� ������Ʈ �����̳�
	vector<Object*> staticObjects;
	// �ؽ�Ʈ �����̳�
	map<string, Text*>mTexts; // string�� �����ϴ� Text*�� �����°�
	// ��ư �����̳�
	map<string, Button*> mButtons;

	stack<Scene*>* scenes = nullptr;
	RenderWindow* window = nullptr;

	// ���콺�� ��ġ (���� â ��������)
	Vector2f mousePosition{ 0.f,0.f };	
	bool quit = false;
	

private:

	virtual void Init();

public:

	bool GetQuit() const;
	void EndScene();

	virtual void Input(Event* e);
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};