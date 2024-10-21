#pragma once
enum SoundList
{
	none = 0,
	KnightAttack,
	KnightDamaged,
	KnightDie,
	ArcherAttack,
	ArcherDamaged,
	ArcherDie,
	MageAttack,
	MageDamaged,
	MageDie,
	GoblinAttack,
	GoblinDamaged,
	GoblinDie,
	Max,
};

class SoundManager
{
public:
	static void SetInst()
	{
		if (sm == nullptr)
		{
			sm = new SoundManager();
		}
	}
	static SoundManager* Instance()
	{
		if (sm == nullptr)
		{
			sm = new SoundManager();

		}
		return sm;
	}
	static void DeleteInstance()
	{
		if(sm != nullptr)
			delete sm;
	}

	void PlaySound(string name,SoundList sl);
	

private:
	SoundManager() {}
	static SoundManager* sm;
	int playedSound[SoundList::Max] { 0 };

	void PlayVoice(string name, SoundList voice);

};

