#pragma once
#include "BackGroundObject.h"

class Object; // vector<Object*> vObjects;�� �������� 

class Scene // Scene�� ��ӹ޴� �ֵ��� ���� _ ���� ���� Ŭ������ ����°�
{
public:
	Scene();
	Scene(stack<Scene*>* scenes); // scene�����͸� ����ִ� stack�� ������ 
	virtual ~Scene();

protected:

	// ������ ������Ʈ���� ���� 
	vector<Object*> vObjects;
				// ��> ���Ϳ� ���õǾ������ϱ� v�ٿ��ذ� 

	map<string, Text*>mTexts; // string�� �����ϴ� Text*�� �����°�
	stack<Scene*>* scenes;
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