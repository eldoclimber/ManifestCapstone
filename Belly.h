#pragma once
#include "Skydive.h"
class Belly :
    public Skydive
{
public:
	//JumpType jumpType;
	//std::string jumpTypeString;
	//std::string jumperName;
	//std::string jumpNote;
	//std::string licenseLetter;
	//int cleared;
	//int jumperId;
	//int altitude;
	//int numInGroup;
	//std::vector<int> jumpersInGroup;

	// Constructor with default arguments
	Belly(JumpType jumpType = JumpType::Belly,
		const std::string& jumpTypeString = "Belly",
		const std::string& jumperName = "",
		const std::string& jumpNote = "Belly",
		const std::string& licenseLetter = "",
		int jumperId = 0,
		bool cleared = true,
		int altitude = 12500,
		int numInGroup = 1,
		const std::vector<int>& jumpersInGroup = std::vector<int>())
		: Skydive(jumpType,
			jumpTypeString,
			jumperName,
			jumpNote,
			licenseLetter,
			jumperId,
			cleared,
			altitude,
			numInGroup,
			jumpersInGroup)
	{

	}

};

