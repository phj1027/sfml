#pragma once
#include "Scene.h"
class PauseScene :
    public Scene
{
public:
	PauseScene();
	PauseScene(stack<Scene*>* scenes, RenderWindow* window, SoundSystem* soundSystem);
	~PauseScene();

private:

	virtual void Init();

public:
	virtual void Input(Event* e);
	virtual void Destroy();

	virtual void Update(const float& deltaTime);

	virtual void Render(RenderWindow* window);

};
