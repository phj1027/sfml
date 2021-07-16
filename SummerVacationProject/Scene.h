#pragma once
#include "BackGroundObject.h"
#include "Button.h"
#include "SoundSystem.h"

class Object; // vector<Object*> vObjects;�� �������� 

class Scene // Scene�� ��ӹ޴� �ֵ��� ���� _ ���� ���� Ŭ������ ����°�
{
public:
	Scene();
	Scene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem); // ������ �����츦 �������ְ��� ��������´�� �������ִ´��
	Scene(const Scene&) = delete;
	Scene* operator = (const Scene&) = delete;
	virtual ~Scene() = default;

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
	SoundSystem* soundSystem = nullptr;
	Object* backGround = nullptr;
	vector<Object*> objects;
	

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