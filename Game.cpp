
#include "Game.h"

using namespace std;

Game::Game(string n) : player_(n), mouse_(0,0), snake_(0,0,3), nut_(8,9) {

}

void Game::set_up(UserInterface* pui)
{
	// set up the holes
	//underground_.set_hole_no_at_position(0, 4, 3);
	//underground_.set_hole_no_at_position(1, 15, 10);
	//underground_.set_hole_no_at_position(2, 7, 15);
	// mouse state already set up in its contructor
	// set up snake
	vector<MoveableGridItem*> elements{ &mouse_,&snake_,&nut_ };
	for (int i = 0; i < elements.size(); i++) {
		int set = false;
		while (!set) {
			elements[i]->position_at_random();
			if (!isObjectAtPosistion(elements[i]->get_x(), elements[i]->get_y(), i)) {
				set = true;
			}
		}
		}
	//snake_.position_at_random();

	snake_.spot_mouse(&mouse_);

	// set up the UserInterface
	p_ui = pui;
}

void Game::run()
{
	assert(p_ui != nullptr);

	p_ui->draw_grid_on_screen(prepare_grid());
	key_ = p_ui->get_keypress_from_user();

	while (!has_ended(key_))

	{ // cheeking for input if game not end

	//	if (is_arrow_key_save) {





		//}
		if (is_arrow_key_code(key_))
		{
			mouse_.scamper(key_, nut_);
			if (CheatMode == false)
			{
				snake_.chase_mouse();
			}

			p_ui->draw_grid_on_screen(prepare_grid());
			apply_rules();
		}
		else
			if (enableCheatMode())
			{
				if (CheatMode == false)
				{
					CheatMode = true;
					cout << "\t\tCHEATMODE ENABLED \n";
					cout << "\t\t\t Snake has stopped moving!";
				}

				else
				{
					CheatMode = false;
					cout << "\t\tCHEATMODE DISABLED ";
					


				}

			}
			else 
				if (is_arrow_key_save(key_)){
			 
				save_game(); 
			}
			else if (is_arrow_key_load(key_)) {

				load_game();
			}

		key_ = p_ui->get_keypress_from_user();
	}
	if (nut_.has_been_collected() && mouse_.has_escaped())
		player_.update_score(1);
	p_ui->show_results_on_screen(prepare_end_message());
	p_ui->show_results_on_screen("\n Press y to continue, anything else to quit");
	key_ = p_ui->get_keypress_from_user();
	if (is_continue_key_code(key_)) {
		play_ = true;
		reset();
	}
	else {
		play_ = false;
	}
}

string Game::prepare_grid() const
{
	// this function builds up a big string which holds the entire game state

	ostringstream os;

	for (int row(1); row <= SIZE; ++row)
	{
		for (int col(1); col <= SIZE; ++col)
		{
			if ((row == snake_.get_y()) && (col == snake_.get_x()))
			{
				os << snake_.get_symbol();
			}
			else
			{
				if ((row == mouse_.get_y()) && (col == mouse_.get_x()))
				{
					os << mouse_.get_symbol();
				}
				else
				{

					if (underground_.is_Hole(col,row))
						os << underground_.get_hole_symbol();
					else
						if ((row == nut_.get_y()) && (col == nut_.get_x()) && !(nut_.has_been_collected()))
								os << nut_.get_symbol();
						else
							if ((snake_.gridAtTail(row, col)))
								os << snake_.getTailSymbol();
							else
								os << FREECELL;
				}
			}
		}
		if (row == SIZE / 2) {
			os << "\t\t\t" + player_.get_name() + ": " + to_string(player_.get_score())  << " \n\nPress S to Save  \n\nPress L to load  ";
		}
		os << endl;
	}

	return os.str();
}

bool Game::enableCheatMode()
{
	return toupper(key_) == CHEAT;
}

bool Game::is_arrow_key_code(int keycode) const
{
	return (keycode == LEFT) || (keycode == RIGHT) || (keycode == UP) || (keycode == DOWN);
}

void Game::apply_rules()
{
	if (snake_.has_caught_mouse())
	{
		mouse_.die();
	}
	else
	{
		if (mouse_.has_reached_a_hole(underground_))
		{
			if (!nut_.has_been_collected()) {
				mouse_.tunnel(underground_);
			}
			else {
				mouse_.escape_into_hole();
			}
		}
		else 
		{
			if (underground_.is_Hole(nut_.get_x(),nut_.get_y()))
			{
				nut_.disappear();
			}
		}
		
	}
}

bool Game::has_ended(char key) const
{
	return ((key == 'Q') || (!mouse_.is_alive()) || (mouse_.has_escaped()));
}

bool Game::is_arrow_key_save(int keycode) const
{
	return (keycode == 'S');
}
bool Game::is_arrow_key_load (int keycode) const
{
	return (keycode == 'L');
}

string Game::prepare_end_message() const
{
	ostringstream os;
	if (nut_.has_been_collected() && mouse_.has_escaped() )
	{
		os << "\n\nEND OF GAME: THE MOUSE ESCAPED UNDERGROUND AND COLLECTED THE NUT! SCORE + 1";
	}

	else if (mouse_.has_escaped()){

		}
	else
	{
		if (!mouse_.is_alive())
		{
			os << "\n\nEND OF GAME: THE SNAKE ATE THE MOUSE!";
		}
		else
		{
			os << "\n\nEND OF GAME: THE PLAYER ENDED THE GAME!";
		}
	}
	return os.str();
}

bool Game::is_continue_key_code(int keycode) const
{
	return (keycode == CONTINUESMALL) || (keycode == CONTINUEBIG);
}

bool Game::play() const {
	return play_;
}

void Game::reset() {
	snake_.reset();
	mouse_.reset();
	nut_.reset();
}

void Game::end_message() {
	p_ui->show_results_on_screen("\nFINAL SCORE: " + to_string(player_.get_score()));
}

void Game::save_game() const
{
	//string game = prepare_grid();
	ofstream fout;
	fout.open("Game.txt", ios::out);
	if (fout.fail()) cout << "\nError saving game.";
	else             //fout << game; // operator << for Game instances
		fout << mouse_.get_x() << "\n" << mouse_.get_y()
		<< "\n" << snake_.get_x() << "\n" << snake_.get_y() << "\n" 
		<< nut_.get_x() << "\n" << nut_.get_y() << "\n"
        << player_.get_score() << "\n";
		//<< player_.get_name() << "\n"
	fout;
	fout.close();

	// convert integer to string and store in file
	



}
		
void Game::load_game()
{
	ifstream fin;
	fin.open("Game.txt", ios::in);
	if (fin.fail()) cout << "\nError loading game.";
	else {


		int x;
		int y;

		fin >> x >> y;
		mouse_.set_position(x, y);
		snake_.set_position(x, y);
		nut_.set_position(x, y);
		mouse_.set_position(x, y);
	}
	
	
}





bool Game::isObjectAtPosistion(int x, int y, int i) {
	bool clear = true;
	if (mouse_.is_at_position(x, y) && i!= 0) {
		clear = false;
	}
	else {
		if (snake_.is_at_position(x, y) && i != 1) {
			clear = false;
		}
		else {
			if (nut_.is_at_position(x, y) && i != 2) {
				clear = false;
			}
			else {
				if (underground_.is_Hole(x,y)) {
					clear = false;
				}
			}
		}
	}
	return !clear;
}