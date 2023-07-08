#pragma once

#include <iomanip>
#include <iostream>
#include "Skydive.h"
#include "Belly.h"
#include "FreeFly.h"
#include "MenuDisplay.h"
#include "Plane.h"


class core
{
public:
	void initialization();
	void openJumperLog();
	int openPlaneLog();
	int openDailyLog();
	int getUserInput();
	int saveJumperLog();
	int savePlaneLog();
	int saveDailyLog();
	int advanceDailyLog();
	int selectActivePlane();
	int addJumperToActivePlane();
	int removeJumperActivePlane();
	int updateManifest();
	int checkIfPlaneFull();
	int setTakeOffTimer();
	int takeOffTimer(int timervalue);
	int clearTakeOffTimer();
	int takeOffTimerCall();
	int takeOff();
	int weatherHold();
	int exitApp();
};

