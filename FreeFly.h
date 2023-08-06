#pragma once
#include "Skydive.h"
class FreeFly :
    public Skydive
{
public:

	// Constructor with default arguments
	FreeFly(JumpType jumpType = JumpType::Freefly,
		const std::string& jumpTypeString = "Freefly",
		const std::string& jumperName = "",
		const std::string& jumpNote = "Freefly",
		const std::string& licenseLetter = "",
		int jumperId = 0,
		bool cleared = true,
		int altitude = 12500,
		int numInGroup = 1,
		int groupId = 1,
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
			groupId,
			jumpersInGroup)
	{

	}


};

