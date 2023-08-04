// Empty.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "core.h"


enum class MainLoop{
undefined,
running,
exitApp,
error};

//int keepGoing = 1;

int main()
{
	core myCore;
	MenuDisplay menu;
	MainLoop status = MainLoop::running;
	Plane plane;

	//Startup function
	myCore.initialization();

	//Initial Menu
	menu.startMenu();

	//Primary program loop
	while (status != MainLoop::exitApp)
	{
		//Update takeoff timer
		myCore.takeOffTimer(menu.getTimerValue());

		
		menu.updateMenu(menu.menuOption); //TODO:Create object within implementation

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
				menu.startMenu();
				break;
			default:
				break;
		}

		//After menu selection functions
		plane.checkFull();
		myCore.setTakeOffTimer();
		myCore.saveDailyLog();
	}

	//Terminate Program
	myCore.exitApp();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

