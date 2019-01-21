#pragma once
class Score
{
public:
	Score();
	~Score();

	int get_amount() const;
	void set_amount(int);
	void update_amount(int amt);
private:
	int amount_ = 0;
};

