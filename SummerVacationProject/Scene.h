#pragma once

class Object; // vector<Object*> vObjects;�� �������� 

class Scene // Scene�� ��ӹ޴� �ֵ��� ���� _ ���� ���� Ŭ������ ����°�
{
public:
	Scene();
	virtual ~Scene();

protected:

	// ������ ������Ʈ���� ���� 
	vector<Object*> vObjects;
				// ��> ���Ϳ� ���õǾ������ϱ� v�ٿ��ذ� 

private:

	virtual void Init();

public:

	virtual void Update(const float& deltaTime);

	virtual void Render(RenderWindow* window);
						// ��> �׷��� ���� ���� 

};