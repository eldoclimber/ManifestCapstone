#pragma once
#include "Skydive.h"
class FreeFly :
    public Skydive
{
public:
	JumpType jumpType;
	std::string jumpTypeString;
	std::string jumperName;
	std::string jumpNote;
	std::string licenseLetter;
	int cleared;
	int jumperId;
	int altitude;
	int numInGroup;
	std::vector<int> jumpersInGroup;

	// Constructor with default arguments
	FreeFly(JumpType jumpType = JumpType::Freefly, 
		const std::string& jumpTypeString = "Freefly", 
		const std::string& jumperName = "", 
		const std::string& jumpNote = "Freefly",
		const std::string& licenseLetter = "", 
		int jumperId = 0, 
		int cleared = 1,
		int altitude = 12500, 
		int numInGroup = 1, 
		const std::vector<int>& jumpersInGroup = std::vector<int>())
		: jumpType(jumpType),
		jumpTypeString(jumpTypeString), 
		jumperName(jumperName), 
		jumpNote(jumpNote),
		licenseLetter(licenseLetter), 
		jumperId(jumperId),
		cleared(cleared),
		altitude(altitude), 
		numInGroup(numInGroup), 
		jumpersInGroup(jumpersInGroup) {}


};

