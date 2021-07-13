#pragma once
#include "Scene.h"
class TitleScene : public Scene
{
public:
	TitleScene();
	TitleScene(stack<Scene*>* scenes); // scene�����͸� ����ִ� stack�� ������ 
	virtual ~TitleScene();

private:
	Music music;

private:
	virtual void Init();

public:
	//��ӹ����ϱ� �Ȱ��� Scene�� Update, Render�� ȣ���ϱ⶧���� �����ʿ������
	//	���� ���ٸ� virtual��
	virtual void Input(Event* e);
	virtual void Destroy();
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);

};

