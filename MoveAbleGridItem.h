#ifndef MoveableGridItemH
#define MoveableGridItemH

#include "Constants.h"
#include "GridItem.h"
#include "RandomNumberGenerator.h"
class MoveableGridItem : public GridItem {
public:
	// constructor
	MoveableGridItem(const int x, const int y, const char symbol);
	int get_x() const;
	int get_y() const;
	bool is_at_position(const int x, const int y) const;
	void update_position(const int dx, const int dy);
	void reset_position(const int x, const int y);
	void position_at_random();
	void set_position(const int, const int);
private:
	int x_, y_;
	RandomNumberGenerator rng_;
};

#endif