#ifndef GameH 
#define GameH 

#include "Mouse.h"
#include"Snake.h"
#include"UserInterface.h"
#include "Nut.h"
#include "Player.h"
#include "Underground.h"
#include <iostream>
#include <sstream>
#include <fstream>

class Game {
public:
	Game(string);
	
	void set_up(UserInterface* pui);
	void run();
	string prepare_grid() const;
	bool is_arrow_key_code(int keycode) const;
	void apply_rules();
	//int find_hole_number_at_position(int x, int y) const;
	bool has_ended(char key) const;
	bool is_arrow_key_save(int keycode) const;
	bool is_arrow_key_load(int keycode) const;
	string prepare_end_message() const;
	bool is_continue_key_code(int) const;
	bool play() const;
	void end_message();
	bool enableCheatMode();
	bool isObjectAtPosistion(int, int, int);
private:
	bool CheatMode = false;
	void reset();
	bool play_;
	int key_;
	bool got_nut;
	Mouse mouse_;
	Snake snake_;
	Nut nut_;
	Underground underground_;
	UserInterface* p_ui;
	Player player_;
	void save_game() const;
	void load_game(); 
	
	

};

#endif