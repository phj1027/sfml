#pragma once
#include "AnimationObject.h"

enum CHARACTER_STATE
{
	IDLE,
	RIGHTWALK,
	LEFTWALK,
	RIGHTRUN,
	LEFTRUN,
	JUMP,
	PUNCH
};

class Character : public AnimationObject
{
public:
	Character();
	virtual ~Character();

private:

	float gravity = 5.f; // �߷�

	//�����ͷ� ���� ���� �׶��׶� �����Ҵ� �س��� ĳ���Ͱ� ����� �� ���⼭ Ǯ���ָ� �Ǵϱ�
	vector<Texture*> idleAnimation;
	vector<Texture*> rightwalkAnimation;
	vector<Texture*> leftwalkAnimation;
	vector<Texture*> rightrunAnimation;
	vector<Texture*> leftrunAnimation;
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

