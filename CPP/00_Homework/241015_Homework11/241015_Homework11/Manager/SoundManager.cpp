#include "../framework.h"
#include "SoundManager.h"

SoundManager* SoundManager::sm = nullptr;

void SoundManager::PlaySound(string name, SoundList sl)
{
	if (playedSound[sl] < 3)
	{
		playedSound[sl] = playedSound[sl] + 1;
		PlayVoice(name, sl);
	}
}

void SoundManager::PlayVoice(string name, SoundList voice)
{
	switch (voice)
	{
	case none:
		break;
	case KnightAttack:
		cout << name << " : Yap!" << endl;
		break;
	case KnightDamaged:
		cout << name << " : Ouch!" << endl;
		break;
	case KnightDie:
		cout << name << " : Arrrrrrrrrr!" << endl;
		break;
	case ArcherAttack:
		cout << name << " : Ho!" << endl;
		break;
	case ArcherDamaged:
		cout << name << " : Oops!" << endl;
		break;
	case ArcherDie:
		cout << name << " : ..." << endl;
		break;
	case MageAttack:
		cout << name << " : I'll burn you!" << endl;
		break;
	case MageDamaged:
		cout << name << " : Ouch!" << endl;
		break;
	case MageDie:
		cout << name << " : I'll be back!" << endl;
		break;
	case GoblinAttack:
		cout << name << " : Krrrrrrrr!" << endl;
		break;
	case GoblinDamaged:
		cout << name << " : arrrrrrrrr!" << endl;
		break;
	case GoblinDie:
		cout << name << " : kyak!" << endl;
		break;
	case Max:
		break;
	default:
		break;
	}
}
