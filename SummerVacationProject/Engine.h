#pragma once

// ���� ��ü�� �̸��� Ŭ���� - ���� ��ó,Ŭ���̾�Ʈ ������ �̰ž����� ������ ��������

class Engine final // final : ���̻� �� Ŭ�������� ��ӹ��� �ʴ´�.
{

public: // ������, �Ҹ���

	Engine();
	~Engine();

private: // ��� ����

	// ������Ʈ���� �׸������� �����츦 ����
	RenderWindow* window = nullptr;
	Event evt;

	// ���� ��ü�� ���� �ð�
	Clock timer;
	float deltaTime = 0.f; // �������� deltaTime������ ��� ������Ʈ�� �ð��� �°� �����ٰ�

private: // �޼ҵ�

	// ������ �ʱ�ȭ �ϴ� �Լ�
	void Init();

	// ���� ����ִ� ������Ʈ�� ������Ʈ�Ѵ�.
	void Update();

	// ������ ���� �Է°��� ó���Ѵ�.
	void Input();

public:

	// �����쿡 ������� ����Ѵ�.
	void Render();

	// ������ ������������ ȣ��Ǵ� �Լ�
	void Destroy();


};

