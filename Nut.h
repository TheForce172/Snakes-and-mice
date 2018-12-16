#ifndef NutH
#define NutH

#include "Constants.h"
#include "MoveableGridItem.h"

class Nut : public MoveableGridItem{
public:
	// constructor
	Nut(int, int);

	bool has_been_collected() const;

	void disappear();

	void reset();

private:
	// data members		
	bool collected_;

	

	

};

#endif