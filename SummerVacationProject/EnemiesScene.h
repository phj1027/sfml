#pragma once
#include "Scene.h"
class EnemiesScene : public Scene
{
public:
	EnemiesScene();
	virtual ~EnemiesScene();

private:
	virtual void Init();

public:
	//��ӹ����ϱ� �Ȱ��� Scene�� Update, Render�� ȣ���ϱ⶧���� �����ʿ������
	//	���� ���ٸ� virtual��
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);

};

