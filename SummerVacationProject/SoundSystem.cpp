#include "framework.h"
#include "SoundSystem.h"

// 사운드가 많아지면 여기서 관리하면 됨 (사운드는 여러개지만 사운드시스템은 1개로 규칙)

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
	
	sound->setBuffer(*soundBuffer);   // soundBuffer가 텍스쳐 역할 sound가 스프라이트 역할
	sound->setVolume(this->volume);
	sound->setLoop(this->loop);

	// 초기화 되자마자 실행 , 내가 정한곳에서만 플레이하고싶으면 생략 
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
	effectSound[effectName]->setLoop(false); // 효과음은 반복되지않기때문에 
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
