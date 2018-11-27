#ifndef MouseH 
#define MouseH 


#include "constants.h"
#include "Underground.h"

class Mouse
{
	public:
		// constructor
		Mouse();

		// assessors
		int get_x();
		int get_y();
		char get_symbol() const;
		bool is_at_position(int x, int y);
		bool is_alive() const;
		bool has_escaped() const;
		bool has_reached_a_hole(Underground ug);

		// mutators
		void die();
		void escape_into_hole();
		void scamper(char k);



	private:
		// data members		
		char symbol_;
		int  x_, y_;
		bool alive_;
		bool escaped_;
		int mouse_dx_;
		int mouse_dy_;

		// supporting functions 
		void position_in_middle_of_grid();
		void update_position(int dx, int dy);
};

#endif