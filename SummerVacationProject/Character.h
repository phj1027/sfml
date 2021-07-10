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
	virtual void Update(const float& deltaTime);
};

