#include <iostream>		// for output and input
using namespace std;

#include "UserInterface.h"
#include "Game.h"

// using OO approach

int main()
{
	UserInterface ui;
	cout << "Please input your Name";
	string n;
	cin >> n;
	Game game(n);
	do {
		game.set_up(&ui);
		game.run();
	} while (game.play());
	game.end_message();
	ui.hold_window();
	return 0;
}