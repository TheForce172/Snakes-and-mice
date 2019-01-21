#include "Score.h"



Score::Score() : amount_(0)
{
}


Score::~Score()
{
}

int Score::get_amount() const
{
	return amount_;
}

void Score::update_amount(int amt) {
	amount_ += amt;
}
void Score::set_amount(int i) {
	amount_ = i;
}
