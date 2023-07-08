// Empty.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "core.h"


enum MainLoop{
undefined,
running,
exit,
error};


int main()
{
	core core;
	MenuDisplay menu;
	MainLoop status = running;
	Plane plane;

	//Startup function
	core.initialization();

	//Initial Menu
	menu.startMenu();

	//Primary program loop
	while (status != exit)
	{
		//Update takeoff timer
		core.takeOffTimer(menu.getTimerValue());

		menu.updateMenu(); //TODO:Create object within implementation

		//Get user input for menu selection
		switch (menu.getMenuOptionUser()) {

			case MenuOptions::undefined:
				break;
			case MenuOptions::addJumper:
				break;
			case MenuOptions::editJumper:
				break;
			case MenuOptions::editPlane:
				break;
			case MenuOptions::addPlane:
				break;
			case MenuOptions::newDay:
				break;
			case MenuOptions::closeDay:
				break;
			case MenuOptions::saveDay:
				break;
			case MenuOptions::newLog:
				break;
			case MenuOptions::editLog:
				break;
			case MenuOptions::newTandem:
				break;
			case MenuOptions::exit:
				break;
			case MenuOptions::showManifest:
				break;
			default:
				break;
		}

		//After menu selection functions
		plane.checkFull();
		core.setTakeOffTimer();
		core.saveDailyLog();
	}

	//Terminate Program
	core.exitApp();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

