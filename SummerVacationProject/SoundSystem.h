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
	Sound* sound = nullptr;
	SoundBuffer* soundBuffer = nullptr;

	float volume = 70.f;
	bool loop = false;

private:

	void Init();


public:
	void Destroy();
	void Play(); // 소리재생
	void Pause();
	void Stop();

};

