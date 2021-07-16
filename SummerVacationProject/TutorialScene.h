#pragma once
#include "Scene.h"
class TutorialScene :
    public Scene
{

public:
	TutorialScene();
	TutorialScene(stack<Scene*>* scenes,RenderWindow* window, SoundSystem* soundSystem);
	~TutorialScene();

private:
	Music music;

private:

	virtual void Init();

public:
	virtual void Input(Event* e);
	virtual void Destroy();
	virtual void Update(const float& deltaTime);
	virtual void Render(RenderWindow* window);

};

