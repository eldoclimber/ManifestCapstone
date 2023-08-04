#include "MenuDisplay.h"
#include <iostream>


int MenuDisplay::startMenu()
{
	clearScreen();
	std::cout << "Start Menu:\n";
	std::cout << "1. New Log\n";
	std::cout << "2. Edit Log\n";
	std::cout << "3. Exit\n";
	std::cout << "Please enter your option: ";
	
	std::cin >> option;
	if (option == 1) {
		menuOption = MenuOptions::newLog;
	}
	else if (option == 2) {
		menuOption = MenuOptions::editLog;
	}
	else if (option == 3) {
		menuOption = MenuOptions::exit;
	}
	return option;
}


int MenuDisplay::mainMenu()
{
	clearScreen();
	std::cout << "Main Menu:\n";
	std::cout << "1. Add Jumper\n";
	std::cout << "2. Edit Jumper\n";
	std::cout << "3. Add Plane\n";
	std::cout << "4. Exit\n";
	std::cout << "Please enter your option: ";
	std::cin >> option;
	if (option == 1) {
		menuOption = MenuOptions::addJumper;
	}
	else if (option == 2) {
		menuOption = MenuOptions::editJumper;
	}
	else if (option == 3) {
		menuOption = MenuOptions::addPlane;
	}
	else if (option == 4) {
		menuOption = MenuOptions::showManifest;
	}
	return option;
}


int MenuDisplay::createPlaneMenu() 
{
	clearScreen();
	std::cout << "Create Plane Menu:\n";
	std::cout << "1. Plane Model\n";
	std::cout << "2. Plane Capacity\n";
	std::cout << "3. Back to Main Menu\n";
	std::cout << "Please enter your option: ";
	std::cin >> option;
	if (option == 1) {
		menuOption = MenuOptions::newLog;
	}
	else if (option == 2) {
		menuOption = MenuOptions::editLog;
	}
	else if (option == 3) {
		menuOption = MenuOptions::showManifest;
	}
	return option;
}

int MenuDisplay::newLoadMenu() 
{
	clearScreen();
	std::cout << "New Load Menu:\n";
	std::cout << "1. Enter Load Details\n";
	std::cout << "2. Review Load\n";
	std::cout << "3. Back to Main Menu\n";
	std::cout << "Please enter your option: ";
	std::cin >> option;
	if (option == 1) {
		menuOption = MenuOptions::newLog;
	}
	else if (option == 2) {
		menuOption = MenuOptions::editLog;
	}
	else if (option == 3) {
		menuOption = MenuOptions::showManifest;
	}
	return option;
}

int MenuDisplay::createJumperMenu() 
{
	clearScreen();
	std::cout << "Create Jumper Menu:\n";
	std::cout << "1. Enter Jumper Details\n";
	std::cout << "2. Review Jumper\n";
	std::cout << "3. Back to Main Menu\n";
	std::cout << "Please enter your option: ";
	std::cin >> option;
	if (option == 1) {
		menuOption = MenuOptions::newLog;
	}
	else if (option == 2) {
		menuOption = MenuOptions::editLog;
	}
	else if (option == 3) {
		menuOption = MenuOptions::showManifest;
	}
	return option;
}



int MenuDisplay::editLogMenu() 
{
	clearScreen();
	std::cout << "Edit Log Menu:\n";
	std::cout << "1. Select Log to Edit\n";
	std::cout << "2. Change Log Details\n";
	std::cout << "3. Delete Log\n";
	std::cout << "4. Back to Main Menu\n";
	std::cout << "Please enter your option: ";
	std::cin >> option;
	if (option == 1) {
		menuOption = MenuOptions::addJumper;
	}
	else if (option == 2) {
		menuOption = MenuOptions::editJumper;
	}
	else if (option == 3) {
		menuOption = MenuOptions::addPlane;
	}
	else if (option == 4) {
		menuOption = MenuOptions::showManifest;
	}
	return option;
}



int MenuDisplay::editDaily() 
{
	clearScreen();
	std::cout << "Edit Daily Menu:\n";
	std::cout << "1. Change Daily Details\n";
	std::cout << "2. Review Daily Log\n";
	std::cout << "3. Delete Daily Log\n";
	std::cout << "4. Back to Main Menu\n";
	std::cout << "Please enter your option: ";
	std::cin >> option;
	if (option == 1) {
		menuOption = MenuOptions::addJumper;
	}
	else if (option == 2) {
		menuOption = MenuOptions::editJumper;
	}
	else if (option == 3) {
		menuOption = MenuOptions::addPlane;
	}
	else if (option == 4) {
		menuOption = MenuOptions::showManifest;
	}
	return option;
}

int MenuDisplay::editJumper() 
{
	clearScreen();
	std::cout << "Edit Jumper Menu:\n";
	std::cout << "1. Select Jumper to Edit\n";
	std::cout << "2. Change Jumper Details\n";
	std::cout << "3. Delete Jumper\n";
	std::cout << "4. Back to Main Menu\n";
	std::cout << "Please enter your option: ";
	std::cin >> option;
	if (option == 1) {
		menuOption = MenuOptions::addJumper;
	}
	else if (option == 2) {
		menuOption = MenuOptions::editJumper;
	}
	else if (option == 3) {
		menuOption = MenuOptions::addPlane;
	}
	else if (option == 4) {
		menuOption = MenuOptions::showManifest;
	}
	return option;
}

int MenuDisplay::editPlane() 
{
	clearScreen();
	std::cout << "Edit Plane Menu:\n";
	std::cout << "1. Select Plane to Edit\n";
	std::cout << "2. Change Plane Details\n";
	std::cout << "3. Delete Plane\n";
	std::cout << "4. Back to Main Menu\n";
	std::cout << "Please enter your option: ";
	std::cin >> option;
	if (option == 1) {
		menuOption = MenuOptions::addJumper;
	}
	else if (option == 2) {
		menuOption = MenuOptions::editJumper;
	}
	else if (option == 3) {
		menuOption = MenuOptions::addPlane;
	}
	else if (option == 4) {
		menuOption = MenuOptions::showManifest;
	}
	return option;
}


MenuOptions MenuDisplay::getMenuOptionUser()
{
	return menuOption;
}


void MenuDisplay::updateMenu(MenuOptions menuOption)
{
	clearScreen();
	switch (menuOption)
	{
	case MenuOptions::newLog:
		newLoadMenu();
		break;
	case MenuOptions::editLog:
		editLogMenu();
		break;
	case MenuOptions::addJumper:
		createJumperMenu();
		break;
	case MenuOptions::editJumper:
		editJumper();
		break;
	case MenuOptions::addPlane:
		createPlaneMenu();
		break;
	case MenuOptions::editPlane:
		editPlane();
		break;
	case MenuOptions::closeDay:
		// Assuming closeDayMenu() is a function you have defined.
		//closeDayMenu();
		break;
	case MenuOptions::newDay:
		// Assuming newDayMenu() is a function you have defined.
		//newDayMenu();
		break;
	case MenuOptions::saveDay:
		// Assuming saveDayMenu() is a function you have defined.
		//saveDayMenu();
		break;
	case MenuOptions::exit:
		// Assuming exitMenu() is a function you have defined.
		//exitMenu();
		break;
	case MenuOptions::newTandem:
		//tandemMenu();
		break;
	case MenuOptions::showManifest:
		// Assuming showManifestMenu() is a function you have defined.
		//showManifestMenu();
		break;
	case MenuOptions::undefined:
	default:
		mainMenu();
		break;
	}
}


void MenuDisplay::setTimerValue(int value)
{
	timerValue = value;
}

int MenuDisplay::getTimerValue()
{
	return timerValue;
}

void MenuDisplay::clearScreen() {
	system("cls");
}
