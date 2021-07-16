#include "framework.h"
#include "SoundSystem.h"

// ���尡 �������� ���⼭ �����ϸ� �� (����� ���������� ����ý����� 1���� ��Ģ)

SoundSystem::SoundSystem()
{
	Init();
}

SoundSystem::SoundSystem(const string& soundFilePath, bool loop) : filePath(soundFilePath), loop(loop)
{
	Init();
}

SoundSystem::~SoundSystem()
{

}

void SoundSystem::Init()
{
	sound = new Sound;
	soundBuffer = new SoundBuffer;

	if (!soundBuffer->loadFromFile(filePath))
	{
		cout << "not load sound - " << filePath << endl;
	}
	
	sound->setBuffer(*soundBuffer);   // soundBuffer�� �ؽ��� ���� sound�� ��������Ʈ ����
	sound->setVolume(this->volume);
	sound->setLoop(this->loop);

	// �ʱ�ȭ ���ڸ��� ���� , ���� ���Ѱ������� �÷����ϰ������ ���� 
	//sound->play();

}

void SoundSystem::Destroy()
{
	DELETE(soundBuffer);
	DELETE(sound);
}

void SoundSystem::Play()
{
	sound->play();
}

void SoundSystem::Pause()
{
	sound->pause();
}

void SoundSystem::Stop()
{
	sound->stop();
}
