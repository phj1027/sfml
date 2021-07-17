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
	BGMsound = new Sound;
	BGMsoundBuffer = new SoundBuffer;

	if (!BGMsoundBuffer->loadFromFile(filePath))
	{
		cout << "not load sound - " << filePath << endl;
	}
	
	BGMsound->setBuffer(*BGMsoundBuffer);   // soundBuffer가 텍스쳐 역할 sound가 스프라이트 역할
	BGMsound->setVolume(this->BGMvolume);
	BGMsound->setLoop(this->loop);

	// 초기화 되자마자 실행 , 내가 정한곳에서만 플레이하고싶으면 생략 
	//sound->play();

}

void SoundSystem::Destroy()
{
	DELETE(BGMsoundBuffer);
	DELETE(BGMsound);

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

void SoundSystem::VolumeDown()
{
	if (BGMvolume > 5.f)
	{
		BGMvolume -= this->volumeDistance;
		BGMsound->setVolume(BGMvolume);
	}

}

void SoundSystem::VolumeUp()
{
	if (BGMvolume < 200.f)
	{
		BGMvolume += this->volumeDistance;
		BGMsound->setVolume(BGMvolume);
	}
	
}

void SoundSystem::EffectVolumeDown()
{
	if (effectVolume > 5.f)
	{
		for (auto& s : effectSound)
		{
			effectVolume -= volumeDistance;
			s.second->setVolume(effectVolume);
		}
	}
}

void SoundSystem::EffectVolumeUp()
{

	if (effectVolume < 200.f)
	{
		for (auto& s : effectSound)
		{
			effectVolume += volumeDistance;
			s.second->setVolume(effectVolume);
		}
	}
}

void SoundSystem::Play()
{
	BGMsound->play();
}

void SoundSystem::Pause()
{
	BGMsound->pause();
}

void SoundSystem::Stop()
{
	BGMsound->stop();
}
