#pragma once

// BGM, Effect Sound

class SoundSystem final // ����ʿ������ final
{
public:

	SoundSystem();
	SoundSystem(const SoundSystem&) = delete;// ����ý��� ������ ����Ǹ�ȵǴϱ� ��������� �����ֱ�
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

	void VolumeDown(); // ������� ����
	void VolumeUp();

	void EffectVolumeDown();  // ȿ�������� ����
	void EffectVolumeUp();

	void Play(); // �Ҹ����
	void Pause();
	void Stop(); // �Ҹ�����

};

