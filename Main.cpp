#include <iostream>		// for output and input
using namespace std;

#include "UserInterface.h"
#include "Game.h"

// using OO approach
UserInterface ui;

int main()
{
	Game game;

	game.set_up(&ui);
	game.run();

	ui.hold_window();
	return 0;
}