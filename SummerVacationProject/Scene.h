#pragma once
#include "BackGroundObject.h"
#include "Button.h"

class Object; // vector<Object*> vObjects;를 쓰기위해 

class Scene // Scene은 상속받는 애들이 많음 _ 지금 마더 클래스를 만드는것
{
public:
	Scene();
	Scene(stack<Scene*>* scenes, RenderWindow* window); // 씬마다 윈도우를 가질수있게함 없으면없는대로 있으면있는대로
	virtual ~Scene();

protected:

	// 애니메이션이 되는 오브젝트 컨테이너
	vector<Object*> animationObjects;
	// 애니메이션이 없는 오브젝트 컨테이너
	vector<Object*> staticObjects;
	// 텍스트 컨테이너
	map<string, Text*>mTexts; // string에 대응하는 Text*가 나오는것
	// 버튼 컨테이너
	map<string, Button*> mButtons;

	stack<Scene*>* scenes = nullptr;
	RenderWindow* window = nullptr;

	// 마우스의 위치 (게임 창 내에서의)
	Vector2f mousePosition{ 0.f,0.f };	
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