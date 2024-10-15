#include "Player.h"

#include "../framework.h"

Player::Player(string name, int hp, int atk, int speed)
{
	this->_name = name;
	this->_hp = hp;
	this->_atk = atk;
	this->_spd = speed;
	this->_coolTime = 0;
}
