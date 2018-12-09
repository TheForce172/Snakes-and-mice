#ifndef UndergroundH
#define UndergroundH 


#include <cassert>
#include <vector>

#include "constants.h"
#include "Hole.h"

using namespace std;

class Underground
{
	public:
		Underground(vector<Hole> list);
		Hole get_hole_no(int no) const;
		void set_hole_no_at_position(int no, int x, int y);
		int get_num_holes() const;
	private:
		bool is_valid_hole_number(int n) const;
		const vector<Hole> holes_;
};

#endif