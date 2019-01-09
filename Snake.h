#ifndef SnakeH
#define SnakeH 

#include "Mouse.h"
#include "MoveableGridItem.h"
class Snake : public MoveableGridItem{
	public:
		Snake(int, int, int);
		~Snake();
		bool has_caught_mouse() const;
		void spot_mouse(Mouse* p_mouse);
		void chase_mouse();
		void reset();
		char getTailSymbol() const;
		bool gridAtTail(int row, int col) const;
// getter 

private:
	void moveTail(int snake_dx, int snake_dy);
	vector<MoveableGridItem> tail_;
	Mouse* p_mouse_;
	void set_direction(int& dx, int& dy);
};

#endif 