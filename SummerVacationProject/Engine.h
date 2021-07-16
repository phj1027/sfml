#pragma once
#include "SoundSystem.h"

class Scene;

// ���� ��ü�� �̸��� Ŭ���� - ���� ��ó,Ŭ���̾�Ʈ ������ �̰ž����� ������ ��������
class Engine final // final : ���̻� �� Ŭ�������� ��ӹ��� �ʴ´�.
{

public: // ������, �Ҹ���

	Engine();
	Engine(const Engine&) = delete;
	Engine& operator=(const Engine&) = delete;
	~Engine();

private: // ��� ���� 

	// ������Ʈ���� �׸������� �����츦 ����
	RenderWindow* window = nullptr;
	SoundSystem* soundSystem = nullptr;
	stack<Scene*> scenes;
	Event* evt = nullptr;

	// ���� ��ü�� ���� �ð�
	Clock* timer = nullptr;
	float deltaTime = 0.f; // �������� deltaTime������ ��� ������Ʈ�� �ð��� �°� �����ٰ�
	float elapsedTime = 0.f;

	
	

	Vector2f mousePosition{ 0.f,0.f };

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

