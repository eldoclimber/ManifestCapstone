#include "MenuDisplay.h"
#include <filesystem>



int MenuDisplay::startMenu() {
	clearScreen();
	std::cout << "Start Menu:\n";
	std::cout << "1. New Daily Log\n";
	std::cout << "2. Enter Manifest menu\n";
	std::cout << "3. Exit\n";
	std::cout << "Please enter your option: ";

	std::cin >> option;
	while (std::cin.fail() || option < 1 || option > 3) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Please enter a number between 1 and 3: ";
		std::cin >> option;
	}
	if (option == 1) {
		menuOption = MenuOptions::newLog;

		// Using myCore functionality to handle this
		std::string filename = myCore.createNewDailyLog();

		if (filename.empty()) {
			std::cerr << "Error creating new log file!\n";
		}
		else {
			std::cout << "New log file '" << filename << "' created successfully!\n";
			//myCore.printJumper(11); //Test function to see the log file is loading properly

			openFile.open(filename, std::ios::in | std::ios::out); // open for reading and writing
			if (!openFile.is_open()) {
				std::cerr << "Error: Could not open file with openFile.\n";
			}
		}
	}
	else if (option == 2) {
		menuOption = MenuOptions::editLog;
		std::string latestFilePath = myCore.getLatestLogFile();

		if (!latestFilePath.empty()) {
			openFile.open(latestFilePath, std::ios::in | std::ios::out); // open for reading and writing
			if (!openFile.is_open()) {
				std::cerr << "Error: Could not open file " << latestFilePath << std::endl;
			}
			else {
				std::cout << "Successfully opened " << latestFilePath << std::endl;
			}
		}
		else {
			std::cerr << "No daily log files found!" << std::endl;
		}
	}
	else if (option == 3) {
		menuOption = MenuOptions::exit;
		openFile.close();
		myCore.exitApp();
	}
	return option;
}



int MenuDisplay::mainMenu()
{
	clearScreen();
	if (displayError == DisplayError::newLogCreated)
		std::cout << "New log file created successfully!\n";
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
	int optionTwo;
	clearScreen();
	std::cout << "New Load Menu:\n";
	std::cout << "1. New plane load\n";
	std::cout << "2. Edit plane Load\n";
	std::cout << "3. Edit plane timer\n";
	std::cout << "4. Show current load details\n";
	std::cout << "5. Send Load\n";
	std::cout << "6. Exit App\n";
	std::cout << "Please enter your option: ";

	std::cin >> option;
	while (std::cin.fail() || option < 1 || option > 6) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Please enter a number between 1 and 6: ";
		std::cin >> option;
	}

	std::vector<JumperInfo> jumperInfos = myCore.getJumpersFromActivePlaneLoad();
	//std::cout << "Debug: jumperInfos size = " << jumperInfos.size() << "\n";
	//if (jumperInfos.empty()) {
	//	std::cout << "No jumpers on the active plane." << std::endl;
	//}
	//else {
	//	std::cout << "Jumpers on the active plane:" << std::endl;
	//	for (const auto& jumperInfo : jumperInfos) {
	//		std::cout << "- ID: " << jumperInfo.id << ", Type: " << jumperInfo.type << ", Group: " << jumperInfo.group << std::endl;
	//	}
	//}


	switch (option) {
	case 1:
		menuOption = MenuOptions::undefined;
		clearScreen();
		std::cout << "Add new plane:\n\n";
		myCore.printPlaneDetails();
		activeTailNumber = myCore.selectActivePlane();  // Select which plane will take the new load.
		//myCore.addJumperToActivePlane();  // Add jumpers to the active plane.
		menuOption = MenuOptions::editLog;
		break;
	case 2:
		menuOption = MenuOptions::editLog;
		std::cout << std::endl << std::endl;
		if (myCore.activePlane) {
			std::cout << "Active Plane: " << myCore.activePlane->name << " (" << myCore.activePlane->tailNumber << ")\n";
		}
		else {
			std::cout << "No active plane selected.\n";
		}
		//myCore.selectActivePlane();  // Let user select which plane load to edit.
		std::cout << "1. Add Jumper\n";
		std::cout << "2. Remove Jumper\n";
		std::cin >> optionTwo;
		if (optionTwo == 1) {
			myCore.addJumperToActivePlane();  // Add jumpers to the selected plane.
			std::cout << "was added to the plane.\n";
		}
		else if (optionTwo == 2) {
			myCore.removeJumperActivePlane();  // Remove jumpers from the selected plane.
			std::cout << "was removed from the plane.\n";
		}
		break;
	case 3:
		menuOption = MenuOptions::editLog;
		myCore.setTakeOffTimer();  // Let user set or edit the take-off timer for the plane.
		break;
	case 4:
		menuOption = MenuOptions::editLog;
		// Display details of the active plane
		if (myCore.activePlane) { // Assuming myCore.activePlane is a pointer to the active Plane
			std::cout << "\nPlane Details:\n";
			std::cout << "Plane Type: " << myCore.activePlane->name << std::endl;
			std::cout << "Pilot: " << myCore.activePlane->pilot << std::endl;
			std::cout << "Tail Number: " << myCore.activePlane->tailNumber << std::endl;
			std::cout << "Max Seats: " << myCore.activePlane->seats << std::endl;
			std::cout << "Estimated Time to Altitude: " << myCore.activePlane->timeToAltitude << " minutes\n";
		}
		else {
			std::cout << "No active plane selected.\n";
		}

		// Display details of the jumpers on the active plane.
		if (jumperInfos.empty()) {
			std::cout << "No jumpers on the active plane." << std::endl;
		}
		else {
			std::cout << "\nJumpers on the active plane:" << std::endl;
			for (const auto& jumper : jumperInfos) {
				std::cout << "- ID: " << jumper.id << ", Type: " << jumper.type << ", Group: " << jumper.group << std::endl;
			}
		}

		std::cout << "\nPress enter to continue...";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any leftover data in the input buffer
		std::cin.get();  // Now wait for user's key press



		break;
	case 5:
		//menuOption = MenuOptions::undefined;
		//myCore.savePlaneLog();	//Not needed for current iteration
		//myCore.saveJumperLog();	//Not needed for current iteration
		myCore.saveDailyLog();
		std::cout << "Load sent successfully.\n";
		std::cout << myCore.timer << " seconds left until NOW CALL!" << std::endl;
		std::cout << "\nPress enter to continue...";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear any leftover data in the input buffer
		std::cin.get();  // Now wait for user's key press

		menuOption = MenuOptions::editLog;
		break;

	case 6:
		myCore.exitApp();
		break;
	default:
		std::cerr << "Invalid option selected.\n";
		break;
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

void MenuDisplay::closeDayMenu()
{
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
		//editLogMenu();
		newLoadMenu();
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
		closeDayMenu();
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
		break;
	default:
		mainMenu();
		break;
	}
}


void MenuDisplay::clearScreen() {
	system("cls");
}
