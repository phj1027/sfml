#pragma once
#include "Scene.h"
class LobbyScene : public Scene
{

public:
	LobbyScene();
	LobbyScene(stack<Scene*>* scenes); // scene�����͸� ����ִ� stack�� ������ 
	~LobbyScene();

private:
	virtual void Init();

public:
	//��ӹ����ϱ� �Ȱ��� Scene�� Update, Render�� ȣ���ϱ⶧���� �����ʿ������
	//	���� ���ٸ� virtual��
	virtual void Destroy();
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
	
};

