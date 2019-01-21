#pragma once

#include <string>
#include "Score.h"
using namespace std;
class Player
{
public:
	Player(string);
	~Player();

	string get_name() const;
	int get_score() const;

	void update_score(int amt);
	void set_amount(int i);

private:
	const string name_;
	Score score;
};

