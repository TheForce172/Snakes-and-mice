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
		char get_symbol() const;
		bool is_at_position(int x, int y) const;
		bool is_alive() const;
		bool has_escaped() const;
		bool has_reached_a_hole(Underground ug) const;
		bool can_collect_nut(Nut) const;

		// mutators
		void die();
		void escape_into_hole();
		void scamper(char k);



        // getter

	private:
		// data members		
		bool alive_;
		bool escaped_;
		int mouse_dx_;
		int mouse_dy_;

		// supporting functions 
		void position_in_middle_of_grid();
};

#endif