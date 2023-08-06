#pragma once

#include <iomanip>
#include <iostream>
#include "Skydive.h"
#include "Belly.h"
#include "FreeFly.h"
#include "Plane.h"
#include <fstream>
#include <ctime>
#include <sstream>
#include <filesystem>
#include <chrono>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

namespace fs = std::filesystem;


// Define a structure to hold the plane details in memory
struct Plane {
	std::string name;
	int seats;
	int altitude;
	std::string pilot;
	std::string tailNumber;
	std::string airportCode;
	int timeToAltitude;
	int currentLoadNum = 0;
	std::string dateTime;
};

// Define a structure to hold the jumper details in memory
struct Jumper {
	std::string name;
	int id;
	std::string licenseLetter;
	std::string firstJump;
	std::string lastJump;
	int totalJumps;
};

struct JumperInfo {
	int id;           
	std::string type; 
	int group;        
};

struct PlaneLoad {
	Plane plane;
	std::string dateTime;
	std::vector<JumperInfo> jumpers;
	int loadNum = 1;
};

class core
{
public:
	void initialization();
	void openJumperLog();
	void openPlaneLog();
	void openDailyLog();
	void saveJumperLog();
	void savePlaneLog();
	void saveDailyLog();
	std::string selectActivePlane();
	void addJumperToActivePlane();
	int removeJumperActivePlane();
	int checkIfPlaneFull();
	int setTakeOffTimer();
	int takeOffTimer(int timervalue);
	int clearTakeOffTimer();
	int takeOffTimerCall();
	int takeOff();
	int weatherHold();
	void exitApp();
	void printJumper(const int index); // Prints individual jumper entry for debugging
	std::string createNewDailyLog();
	std::string getLatestLogFile();
	time_t to_time_t_core(const fs::file_time_type& ftime);
	std::vector<JumperInfo> getJumpersFromActivePlaneLoad();
	void printPlaneDetails();

	//Like file streams
	std::fstream openFile;
	std::fstream jumperFile;
	std::fstream planeFile;

	//Storing logs in memory, not good for enterprise level but good enough for this
	std::vector<Plane> planes; 
	std::vector<Jumper> jumpers; 
	std::vector<PlaneLoad> planeLoads;

	//Global Variables

	Plane* activePlane = nullptr;  // Pointer to the currently active plane.
	std::vector<Jumper> activeJumpers;  // Jumpers on the active plane.
	int timer = 60;  // Take-off timer in seconds.

};

