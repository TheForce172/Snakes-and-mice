#ifndef GameH 
#define GameH 

#include "Mouse.h"
#include"Snake.h"
#include"UserInterface.h"
#include <iostream>
#include <sstream>
class Game {
public:

	Game();
	
	void set_up(UserInterface* pui);
	void run();
	string prepare_grid() const;
	bool is_arrow_key_code(int keycode) const;
	void apply_rules();
	int find_hole_number_at_position(int x, int y) const;
	bool has_ended(char key) const;
	string prepare_end_message() const;

private:
	int key_;	
	Mouse mouse_;
	Snake snake_;
	Underground underground_;
	UserInterface* p_ui;
};

#endif