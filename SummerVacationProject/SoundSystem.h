#pragma once

// BGM, Effect Sound

class SoundSystem final // ����ʿ������ final
{
public:

	SoundSystem();
	SoundSystem(const string& soundFilePath, bool loop = false); // loop => �ݺ�������� false�� �⺻��
	SoundSystem(const SoundSystem&) = delete;// ����ý��� ������ ����Ǹ�ȵǴϱ� ��������� �����ֱ�
	SoundSystem& operator=(const SoundSystem&) = delete;
	~SoundSystem();


	string filePath{};
	Sound* BGMsound = nullptr; // ��������Ʈ����
	SoundBuffer* BGMsoundBuffer = nullptr;  // sound���ҽ� ���� �����صα����� ���� (�ؽ��İ���)
	// sound�� soundbuffer�� ���� ����Ǵ°� 

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

	void VolumeDown(); // ������� ����
	void VolumeUp();

	void EffectVolumeDown();  // ȿ�������� ����
	void EffectVolumeUp();

	void Play(); // �Ҹ����
	void Pause();
	void Stop(); // �Ҹ�����

};

