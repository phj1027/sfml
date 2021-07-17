#pragma once

// BGM, Effect Sound

class SoundSystem final // 상속필요없으니 final
{
public:

	SoundSystem();
	SoundSystem(const string& soundFilePath, bool loop = false); // loop => 반복재생관련 false가 기본값
	SoundSystem(const SoundSystem&) = delete;// 사운드시스템 여러개 복사되면안되니까 복사생성자 막아주기
	SoundSystem& operator=(const SoundSystem&) = delete;
	~SoundSystem();


	string filePath{};
	Sound* BGMsound = nullptr; // 스프라이트개념
	SoundBuffer* BGMsoundBuffer = nullptr;  // sound리소스 따로 저장해두기위한 버퍼 (텍스쳐개념)
	// sound는 soundbuffer에 들어가서 재생되는것 

	float BGMvolume = 70.f;
	bool loop = false;

	map<string, Sound*> effectSound;
	map<string, SoundBuffer*> effectSoundBuffer;

	float effectVolume = 50.f;

	const float volumeDistance = 5.f;

private:

	void Init();

public:

	void Destroy();

	void AddEffectSound(const string& soundFilePath, const string& effectName);
	void EffectPlay(const string& effectName);

	void VolumeDown(); // 배경음의 볼륨
	void VolumeUp();

	void EffectVolumeDown();  // 효과음들의 볼륨
	void EffectVolumeUp();

	void Play(); // 소리재생
	void Pause();
	void Stop(); // 소리끄기

};

