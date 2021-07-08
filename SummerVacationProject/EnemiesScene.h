#pragma once
#include "Scene.h"
class EnemiesScene : public Scene
{
public:
	EnemiesScene();
	EnemiesScene(stack<Scene*>* scenes); // scene포인터를 담고있는 stack의 포인터 
	virtual ~EnemiesScene();

private:
	virtual void Init();

public:
	//상속받으니까 똑같은 Scene의 Update, Render를 호출하기때문에 써줄필요없지만
	//	굳이 쓴다면 virtual씀
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);

};

