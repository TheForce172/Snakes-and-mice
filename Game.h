#ifndef GameH 
#define GameH 

#include "Mouse.h"
#include"Snake.h"
#include"UserInterface.h"
#include <iostream>
#include <sstream>
class Game {
public:


	
	void set_up(UserInterface* pui);
	void run();
	string prepare_grid();
	bool is_arrow_key_code(int keycode);
	void apply_rules();
	int find_hole_number_at_position(int x, int y);
	bool has_ended(char key);
	string prepare_end_message();

private:
	int key_;	
	Mouse mouse_;
	Snake snake_;
	Underground underground_;
	UserInterface* p_ui;
};

#endif