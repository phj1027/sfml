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

	for (auto& s : effectSound)
	{
		DELETE(s.second);

	}
	effectSound.clear();

	for (auto& sb : effectSoundBuffer)
	{
		DELETE(sb.second);
	}
	effectSoundBuffer.clear();
}

void SoundSystem::AddEffectSound(const string& soundFilePath, const string& effectName)
{
	effectSound[effectName] = new Sound;
	effectSoundBuffer[effectName] = new SoundBuffer;

	if (!effectSoundBuffer[effectName]->loadFromFile(soundFilePath))
	{
		cout << "not load sound -" << soundFilePath << endl;
	}
	effectSound[effectName]->setBuffer(*effectSoundBuffer[effectName]);
	effectSound[effectName]->setVolume(effectVolume);
	effectSound[effectName]->setLoop(false); // ȿ������ �ݺ������ʱ⶧���� 
}

void SoundSystem::EffectPlay(const string& effectName)
{
	effectSound[effectName]->play();
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
