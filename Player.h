#pragma once

#include <string>
#include "Score.h"
using namespace std;
class Player
{
public:
	Player(string);
	~Player();

	string get_name();
	int get_score();

	void update_score(int amt);
private:
	const string name;
	Score score;
};

