#ifndef SnakeH
#define SnakeH 

#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include "MoveableGridItem.h"
class Snake : public MoveableGridItem{
	public:
		Snake(int, int);
		~Snake();
		bool is_at_position(int x, int y) const;  
		bool has_caught_mouse() const;
		void spot_mouse(Mouse* p_mouse);
		void chase_mouse();
		void set_direction(int& dx, int& dy);
		void position_at_random();
		void update_position(int dx, int dy);

		
// getter 

    int get_x() const;
    int get_y() const;
	char get_symbol() const;

private:
	int x_, y_;		
	const char symbol_;
	RandomNumberGenerator rng_;
	Mouse* p_mouse_;
};

#endif 