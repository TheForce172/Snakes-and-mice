#pragma once
class Score
{
public:
	Score();
	~Score();

	int get_amount() const;
	void update_amount(int amt);
private:
	int amount_;
};

