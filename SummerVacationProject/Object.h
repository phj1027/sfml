#pragma once

class Object : public Sprite  // Object�� Sprite�� ��ӵ�
{
public:

	// ������,�Ҹ���= default -> �⺻ ������ �Ҹ��ڵ�
	Object() = default;
	virtual ~Object() = default; // ��� ���� ���� �����Ƿ� virtual��

private: // �� �ڽŸ� ��밡��

	virtual void Init() = 0;

//protected: // ��ӹ޴� Ŭ�������� ��������
//
//	vector<Texture*> animation;

public:

	// ��ӹ޴� �ֵ��� Init, Destroy, Update�� �ٸ��� �����Ƿ� virtual void ��
	// �Լ� = 0; -> ���������Լ�
	// ��> �� ������Ʈ�� ��ӹ޴� �ֵ��� ��� �� Init,Destroy,Update �Լ��� �ʼ������� �־���ϱ⶧���� ���������Լ��� ��
	virtual void Destroy() = 0;
	virtual void Update(const float& deltaTime) = 0;

};

