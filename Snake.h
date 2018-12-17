#ifndef SnakeH
#define SnakeH 

#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include "MoveableGridItem.h"
class Snake : public MoveableGridItem{
	public:
		Snake(int, int, int);
		~Snake();
		bool has_caught_mouse() const;
		void spot_mouse(Mouse* p_mouse);
		void chase_mouse();
		void reset();
		void moveTail(int snake_dx, int snake_dy);
		char getTailSymbol() const;
		bool gridAtTail(int row, int col) const;
		vector<MoveableGridItem> tail_;
// getter 

private:
	Mouse* p_mouse_;
	void set_direction(int& dx, int& dy);
};

#endif 