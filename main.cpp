// Empty.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "core.h"
#include "MenuDisplay.h"


enum class MainLoop{
undefined,
running,
exitApp,
error};

//int keepGoing = 1;

int main()
{
	core myCore;
	myCore.initialization();
	MenuDisplay menu(myCore);
	MainLoop status = MainLoop::running;
	//Plane plane;


	//Initial Menu
	menu.startMenu();

	//Primary program loop
	while (status != MainLoop::exitApp)
	{
		//Update takeoff timer
		myCore.takeOffTimer(menu.getTimerValue());		
		menu.updateMenu(menu.getMenuOption());


		//After menu selection functions
		//plane.isFull();
		//myCore.saveDailyLog();
	}

	//Terminate Program
	myCore.exitApp();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

