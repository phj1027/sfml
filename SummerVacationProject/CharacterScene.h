#pragma once
#include "Scene.h"
class CharacterScene : public Scene
{
public:
	CharacterScene();
	CharacterScene(stack<Scene*>* scenes); // scene�����͸� ����ִ� stack�� ������ 
	virtual ~CharacterScene();

private:
	virtual void Init();

public:
	//��ӹ����ϱ� �Ȱ��� Scene�� Update, Render�� ȣ���ϱ⶧���� �����ʿ������
	//	���� ���ٸ� virtual��
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);

};

