#include "Underground.h"

// number of holes in underground
const int MAXHOLES(3);

Underground::Underground() : holes_({ Hole(4,3), Hole(15,10), Hole(7,15) })
{
}

/*Hole Underground::get_hole_no(int no) const
{
	// pre-condition: valid hole number
	assert(is_valid_hole_number(no));

	return holes_.at(no);
}

void Underground::set_hole_no_at_position(int no, int x, int y)
{
	// pre-condition: valid hole number
	assert(is_valid_hole_number(no));

	Hole h(x, y);

	switch (no)
	{
		case 0: holes_.at(0) = h; break;
		case 1: holes_.at(1) = h; break;
		case 2: holes_.at(2) = h; break;
	}
} 
*/
bool Underground::is_valid_hole_number(int no) const
{
	return (no >= 0) && (no < holes_.size());
}

size_t Underground::get_num_holes() const{
	return holes_.size();
}

bool Underground::is_Hole(const int x, const int y) const{
	int hole = false;
	for (int i = 0; i < holes_.size(); i++) {
		if (holes_[i].is_at_position(x,y)){
			hole = true;
		}
	}
	return hole;
}

char Underground::get_hole_symbol() const{
	return holes_[0].get_symbol();
}