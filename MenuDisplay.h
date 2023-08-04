#pragma once


enum class MenuOptions {
	undefined,
	newLog,
	editLog,
	addJumper,
	editJumper,
	addPlane,
	editPlane,
	closeDay,
	newDay,
	saveDay,
	exit,
	newTandem,
	showManifest
};

class MenuDisplay
{
public:
	MenuOptions menuOption = MenuOptions::undefined;

    int startMenu();
    int mainMenu();
    int createPlaneMenu();
    int newLoadMenu();
    int createJumperMenu();
    int editLogMenu();
    int editDaily();
    int editJumper();
    int editPlane();
	MenuOptions getMenuOptionUser();
	void updateMenu(MenuOptions menuOption);
	void setTimerValue(int value);
	int getTimerValue();
	void clearScreen();



private:
	int option;
	int timerValue = 0;

};

