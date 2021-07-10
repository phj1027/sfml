#pragma once
#include "AnimationObject.h"

enum CHARACTER_STATE
{
	IDLE,
	WALK,
	RUN,
	JUMP,
	PUNCH
};

class Character : public AnimationObject
{
public:
	Character();
	virtual ~Character();

private:

	// ������ ���� ��������
	Vector2f position{ 0.f,0.f };  // x��ǥ y��ǥ 
	Vector2f velocity{ 0.f,0.f };  // x�� �ӵ� y�� �ӵ� 
	Vector2f acceleration{ 0.f,0.f }; // x�డ�ӵ� y�డ�ӵ� 

	float gravity = 5.f; // �߷�

	//�����ͷ� ���� ���� �׶��׶� �����Ҵ� �س��� ĳ���Ͱ� ����� �� ���⼭ Ǯ���ָ� �Ǵϱ�
	vector<Texture*> idleAnimation;
	vector<Texture*> walkAnimation;
	vector<Texture*> runAnimation;
	vector<Texture*> jumpAnimation;
	vector<Texture*> punchAnimation;

	int state = IDLE;

	//int�ڷ��� �ϳ��� vector�����̳� �ϳ��� ¦���Ŵ
	// ex) WALK�ϳ� �ҷ��ٸ� walkAnimation�� ¦��
	// ex) RUN�ϳ� �ҷ��ٸ� runAnimation�� ¦��
	map<int, vector<Texture*>> stateAnimation;
	// stateAnimation���� Ű��(int�ڷ���)�� �ҷ����� �ش� vector�����̳ʰ� Ƣ����°�

private:
	virtual void Init();

public:
	virtual void Destroy();
	void MoveUpdate();
	virtual void Update(const float& deltaTime);
};

