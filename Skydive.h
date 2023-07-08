#pragma once

#include <string>
#include <vector>

enum class JumpType {
	undefinedJump,
	Belly,
	Tracking,
	Freefly,
	Angle,
	HighPull,
	HopAndPop,
	Crew,
	Flocking,
	AFFTeacher,
	AFFStudent,
	Coaching,
	CoachStudent,
	Tandem,
	Wingsuit,
	InflatibleTracking,
	Competition
};

class Skydive {

public:
	JumpType jumpType;
	std::string jumpTypeString;
	std::string jumperName;
	std::string jumpNote;
	std::string licenseLetter;
	int jumperId;
	int cleared;
	int altitude;
	int numInGroup;
	std::vector<int> jumpersInGroup;



	// Constructor with default arguments
	Skydive(JumpType jumpType = JumpType::undefinedJump, 
		const std::string& jumpTypeString = "", 
		const std::string& jumperName = "", 
		const std::string& jumpNote = "",
		const std::string& licenseLetter = "", 
		int jumperId = 0, 
		int cleared = 1,
		int altitude = 0, 
		int numInGroup = 0, 
		const std::vector<int>& jumpersInGroup = std::vector<int>())
		: jumpType(jumpType), 
		jumpTypeString(jumpTypeString), 
		jumperName(jumperName), 
		jumpNote(jumpNote),
		licenseLetter(licenseLetter), 
		jumperId(jumperId), 
		altitude(altitude), 
		numInGroup(numInGroup), 
		jumpersInGroup(jumpersInGroup) {}


};




