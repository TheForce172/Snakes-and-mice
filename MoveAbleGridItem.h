#ifndef MoveableGridItemH
#define MoveableGridItemH

#include "Constants.h"
#include "GridItem.h"

class MoveableGridItem : public GridItem {
public:
	// constructor
	MoveableGridItem(int x, int y);


	bool is_at_position(int x, int y) const;
	void reset_position(int x, int y);
	void update_position(int x, int y);
	int get_x() const;
	int get_y() const;

private:

	int x, y;

};

#endif