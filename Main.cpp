#include <iostream>		// for output and input
using namespace std;

#include "UserInterface.h"
#include "Game.h"

// using OO approach
UserInterface ui;

int main()
{
	cout << "Please input your Name";
	string n;
	cin >> n;
	Game game(n);
	do {
		game.set_up(&ui);
		game.run();
	} while (game.play());

	ui.hold_window();
	return 0;
}