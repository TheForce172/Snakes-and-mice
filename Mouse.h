#ifndef MouseH 
#define MouseH 


#include "constants.h"
#include "Underground.h"
#include "Nut.h"
#include "MoveableGridItem.h"

class Mouse : public MoveableGridItem{
	public:
		// constructor
		Mouse(int, int);

		// assessors
		//int get_x() const;
		//int get_y() const;
		bool is_alive() const;
		bool has_escaped() const;
		bool has_reached_a_hole(Underground ug) const;
		bool can_collect_nut(Nut) const;

		// mutators
		void die();
		void escape_into_hole();
		void scamper(char k, Nut);
		void reset();
		void tunnel(Underground ug);

        // getter

	private:
		// data members		
		bool alive_;
		bool escaped_;

		// supporting functions 
		void position_in_middle_of_grid();
};

#endif