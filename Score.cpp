#include "Score.h"



Score::Score()
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
