#include "Player.h"


Player::Player(string n) : name_(n)
{
}


Player::~Player()
{
}

string Player::get_name() const{
	return name_;
}

int Player::get_score() const
{
	return score.get_amount();
}

void Player::update_score(int amt)
{
	score.update_amount(amt);
}

void Player::set_amount(int i) {
	score.set_amount(i);
}