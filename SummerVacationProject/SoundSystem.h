#pragma once

// BGM, Effect Sound

class SoundSystem final // 상속필요없으니 final
{
public:

	SoundSystem();
	SoundSystem(const SoundSystem&) = delete;// 사운드시스템 여러개 복사되면안되니까 복사생성자 막아주기
	SoundSystem& operator=(const SoundSystem&) = delete;
	~SoundSystem();


	string nowPlayBGM{};

	map<string, Sound*> BGMSound;
	map<string, SoundBuffer*> BGMSoundBuffer;

	float BGMvolume = 70.f;
	bool loop = false;

	map<string, Sound*> effectSound;
	map<string, SoundBuffer*> effectSoundBuffer;

	float effectVolume = 200.f;

	const float volumeDistance = 5.f;

private:

	void Init();

public:

	void Destroy();

	void AddEffectSound(const string& soundFilePath, const string& effectName);
	void EffectPlay(const string& effectName);

	void AddBGMSound(const string& soundFilePath, const string& BGMName);
	void BGMPlay(const string& BGMName);

	void VolumeDown(); // 배경음의 볼륨
	void VolumeUp();

	void EffectVolumeDown();  // 효과음들의 볼륨
	void EffectVolumeUp();

	void Play(); // 소리재생
	void Pause();
	void Stop(); // 소리끄기

};

