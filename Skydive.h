#pragma once

#include <string>
#include <vector>

enum class JumpType {
	undefinedJump,
	Belly,
	Freefly
};

class Skydive {

protected:
	JumpType jumpType;
	std::string jumpTypeString;
	std::string jumperName;
	std::string jumpNote;
	std::string licenseLetter;
	int cleared;
	int altitude;
	int numInGroup;
	int groupId;
	std::vector<int> jumpersInGroup;



	// Constructor with default arguments
	Skydive(JumpType jumpType = JumpType::undefinedJump, 
		const std::string& jumpTypeString = "", 
		const std::string& jumperName = "", 
		const std::string& jumpNote = "",
		const std::string& licenseLetter = "", 
		int jumperId = 0, 
		bool cleared = true,
		int altitude = 0, 
		int numInGroup = 0,
		int groupId = 1,
		const std::vector<int>& jumpersInGroup = std::vector<int>())
		: jumpType(jumpType), 
		jumpTypeString(jumpTypeString), 
		jumperName(jumperName), 
		jumpNote(jumpNote),
		licenseLetter(licenseLetter), 
		jumperId(jumperId), 
		altitude(altitude), 
		numInGroup(numInGroup),
		groupId(groupId),
		jumpersInGroup(jumpersInGroup) {}

public:
	int jumperId;
	int getJumperId();
};