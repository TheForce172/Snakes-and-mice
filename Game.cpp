
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
	snake_.position_at_random();
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
	{
		if (is_arrow_key_code(key_))
		{
			mouse_.scamper(key_);
			snake_.chase_mouse();
			p_ui->draw_grid_on_screen(prepare_grid());
			apply_rules();
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
					const int hole_no(find_hole_number_at_position(col, row));

					if (hole_no != -1)
						os << underground_.get_hole_no(hole_no).get_symbol();
					else
						if ((row == nut_.get_y()) && (col == nut_.get_x()))
							if (!nut_.has_been_collected()) {
								os << nut_.get_symbol();
							}
							else {
								os << FREECELL;
							}
						else
							if ((snake_.gridAtTail(row, col)))
								os << snake_.getTailSymbol();
							else
								os << FREECELL;
				}
			}
		}
		if (row == SIZE / 2) {
			os << "\t\t\t" + player_.get_name() + ": " + to_string(player_.get_score());
		}
		os << endl;
	}

	return os.str();
}

bool Game::is_arrow_key_code(int keycode) const
{
	return (keycode == LEFT) || (keycode == RIGHT) || (keycode == UP) || (keycode == DOWN);
}

int Game::find_hole_number_at_position(int x, int y) const
{
	for (int h_no(0); h_no < underground_.get_num_holes(); ++h_no)
	{
		if (underground_.get_hole_no(h_no).is_at_position(x, y))
		{
			return h_no;
		}
	}

	return -1; // not a hole
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
			mouse_.escape_into_hole();
		}
		else 
		{
			if (mouse_.can_collect_nut(nut_))
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