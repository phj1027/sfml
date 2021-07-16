#pragma once
#include "Scene.h"
class FirstStageScene :
    public Scene
{

public:
	FirstStageScene();
	FirstStageScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	~FirstStageScene();

private:

	//vector<Object*> jellys;

	//vector<Vector2f> jellyPositions;

private:

	virtual void Init();

public:
	virtual void Input(Event* e);
	virtual void Destroy();

	virtual void Update(const float& deltaTime);

	virtual void Render(RenderWindow* window);

};