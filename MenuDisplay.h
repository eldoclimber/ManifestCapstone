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
    int startMenu();
    int mainMenu();
    int createPlaneMenu();
    int newLoadMenu();
    int createJumperMenu();
    int editLogMenu();
    int editDaily();
    int editJumper();
    int editPlane();
    int tandemMenu();
	MenuOptions getMenuOptionUser();
	int updateMenu();
	void setTimerValue(int value);
	int getTimerValue();

	MenuOptions menuOption = MenuOptions::undefined;

private:
	int timerValue = 0;

};

