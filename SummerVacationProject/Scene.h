#pragma once
#include "BackGroundObject.h"

class Object; // vector<Object*> vObjects;를 쓰기위해 

class Scene // Scene은 상속받는 애들이 많음 _ 지금 마더 클래스를 만드는것
{
public:
	Scene();
	Scene(stack<Scene*>* scenes); // scene포인터를 담고있는 stack의 포인터 
	virtual ~Scene();

protected:

	// 씬에서 오브젝트들을 관리 
	vector<Object*> vObjects;
				// ㄴ> 백터와 관련되어있으니까 v붙여준것 

	map<string, Text*>mTexts; // string에 대응하는 Text*가 나오는것
	stack<Scene*>* scenes;
	bool quit = false;
	

private:

	virtual void Init();

public:

	bool GetQuit() const;
	void EndScene();

	virtual void Input(Event* e);
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);
};