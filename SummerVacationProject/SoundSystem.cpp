#include "framework.h"
#include "SoundSystem.h"

// 사운드가 많아지면 여기서 관리하면 됨 (사운드는 여러개지만 사운드시스템은 1개로 규칙)

SoundSystem::SoundSystem()
{
	Init();
}


SoundSystem::~SoundSystem()
{

}

void SoundSystem::Init()
{
	

}

void SoundSystem::Destroy()
{
	for (auto& s : BGMSound)
	{
		DELETE(s.second);

	}
	BGMSound.clear();

	for (auto& sb : BGMSoundBuffer)
	{
		DELETE(sb.second);
	}

	BGMSoundBuffer.clear();

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

void SoundSystem::AddBGMSound(const string& soundFilePath, const string& BGMName)
{
	BGMSound[BGMName] = new Sound;
	BGMSoundBuffer[BGMName] = new SoundBuffer;

	if (!BGMSoundBuffer[BGMName]->loadFromFile(soundFilePath))
	{
		cout << "not load sound -" << soundFilePath << endl;
	}
	BGMSound[BGMName]->setBuffer(*BGMSoundBuffer[BGMName]);
	BGMSound[BGMName]->setVolume(BGMvolume);
	BGMSound[BGMName]->setLoop(true); // 효과음은 반복되지않기때문에 
}
void SoundSystem::BGMPlay(const string& BGMName)
{
	if (nowPlayBGM.empty())
	{
		nowPlayBGM = BGMName;
		BGMSound[BGMName]->play();
	}
	else
	{
		BGMSound[nowPlayBGM]->stop();
		nowPlayBGM = BGMName;
		BGMSound[BGMName]->play();
	}
}
	

void SoundSystem::VolumeDown()
{
	if (BGMvolume > 5.f)
	{
		for (auto& bgm : BGMSound)
		{
			BGMvolume -= volumeDistance;
			bgm.second->setVolume(BGMvolume);
		}
	}

}

void SoundSystem::VolumeUp()
{
	if (BGMvolume < 200.f)
	{
		for (auto& bgm : BGMSound)
		{
			BGMvolume += this->volumeDistance;
			bgm.second->setVolume(BGMvolume);
		}
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
	BGMSound[nowPlayBGM]->play();
}

void SoundSystem::Pause()
{
	BGMSound[nowPlayBGM]->pause();
}

void SoundSystem::Stop()
{
	BGMSound[nowPlayBGM]->stop();
}
