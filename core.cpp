#include "core.h"

namespace fs = std::filesystem;

// Initialization function that opens the required log files
void core::initialization() {
    openJumperLog();
    openPlaneLog();
    //openDailyLog();
}

void core::openJumperLog() {
    std::ifstream jumperFile("jumper_log.txt");

    if (!jumperFile.is_open()) {
        std::cerr << "Error: Could not open jumper_log.txt file for reading.\n";
        return;
    }

    Jumper currentJumper;
    std::string line;
    while (std::getline(jumperFile, line)) {
        if (line.empty()) continue; // Skip blank lines

        if (line[0] == 'n') {
            currentJumper.name = line.substr(2);
        }
        else if (line[0] == 'i') {
            currentJumper.id = std::stoi(line.substr(2));
        }
        else if (line[0] == 'l') {
            currentJumper.licenseLetter = line.substr(2);
        }
        else if (line[0] == 'f') {
            currentJumper.firstJump = line.substr(2);
        }
        else if (line[0] == 'j') {
            currentJumper.lastJump = line.substr(2);
        }
        else if (line[0] == 't') {
            currentJumper.totalJumps = std::stoi(line.substr(2));
            jumpers.push_back(currentJumper); // Assuming 't' is the last data of a jumper's entry
        }
    }

    jumperFile.close();

}

void core::openPlaneLog() {
    std::ifstream planeFile("planeLog.txt");

    if (!planeFile.is_open()) {
        std::cerr << "Error opening planeLog.txt" << std::endl;
        return;
    }

    // Parse the file
    std::string line;
    while (std::getline(planeFile, line)) {
        Plane plane;

        // Parse name
        if (line[0] == 'n') {
            plane.name = line.substr(2);  // Skip 'n' and space
        }

        // Parse seats
        std::getline(planeFile, line);
        if (line[0] == 's') {
            plane.seats = std::stoi(line.substr(2));
        }

        // Parse altitude
        std::getline(planeFile, line);
        if (line[0] == 'a') {
            plane.altitude = std::stoi(line.substr(2));
        }

        // Parse pilot
        std::getline(planeFile, line);
        if (line[0] == 'p') {
            plane.pilot = line.substr(2);
        }

        // Parse tail number
        std::getline(planeFile, line);
        if (line[0] == 't') {
            plane.tailNumber = line.substr(2);
        }

        // Parse airport code
        std::getline(planeFile, line);
        if (line[0] == 'd') {
            plane.airportCode = line.substr(2);
        }

        // Parse time to altitude
        std::getline(planeFile, line);
        if (line[0] == 'c') {
            plane.timeToAltitude = std::stoi(line.substr(2));
        }

        // Add plane to vector
        planes.push_back(plane);
    }

    planeFile.close();
}

void core::openDailyLog() {
    // Get current date in YYYYMMDD format
    std::time_t t = std::time(nullptr);
    std::tm tm;
    localtime_s(&tm, &t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d");
    std::string dateStr = oss.str();

    // Start with the initial filename
    std::string filename = "daily_log_" + dateStr + ".txt";
    int increment = 1;

    // If that doesn't exist, try incremented filenames
    std::ifstream infile(filename);
    while (!infile.good() && increment <= 10) {  // Adding a limit for safety, change 10 to desired limit or remove limit if needed
        infile.close();
        filename = "daily_log_" + dateStr + "_" + std::to_string(increment) + ".txt";
        increment++;
        infile.open(filename);
    }
    infile.close();

    // Now filename has the name of the file we want to open or it doesn't exist
    openFile.open(filename);
    if (!openFile.is_open()) {
        std::cerr << "Error: Could not open " << filename << " for reading.\n";
        return;
    }

    std::string line;
    PlaneLoad currentLoad;
    JumperInfo currentJumper;

    while (std::getline(openFile, line)) {
        if (line.empty()) continue; // Skip blank lines

        // Splitting line on comma for CSV format
        std::stringstream ss(line);
        std::string segment;

        std::getline(ss, segment, ',');

        if (segment == "Plane:") {
            std::getline(ss, currentLoad.plane.name, ',');
            std::getline(ss, segment, ','); currentLoad.plane.seats = std::stoi(segment);
            std::getline(ss, segment, ','); currentLoad.plane.altitude = std::stoi(segment);
            std::getline(ss, currentLoad.plane.pilot, ',');
            std::getline(ss, currentLoad.plane.tailNumber, ',');
            std::getline(ss, currentLoad.plane.airportCode, ',');
            std::getline(ss, segment, ','); currentLoad.plane.timeToAltitude = std::stoi(segment);
            std::getline(ss, segment, ','); currentLoad.plane.currentLoadNum = std::stoi(segment);
        }
        else if (segment == "DateTime:") {
            std::getline(ss, currentLoad.dateTime, ',');
        }
        else if (segment == "Load Number:") {
            std::getline(ss, segment, ',');
            currentLoad.loadNum = std::stoi(segment);
        }
        else {
            currentJumper.id = std::stoi(segment);
            std::getline(ss, currentJumper.type, ',');
            std::getline(ss, segment, ',');
            currentJumper.group = std::stoi(segment);

            currentLoad.jumpers.push_back(currentJumper);

            // Check next line if it starts a new plane load
            std::streampos currentPos = openFile.tellg();
            if (std::getline(openFile, line) && line.substr(0, 6) == "Plane:") {
                planeLoads.push_back(currentLoad);
                currentLoad.jumpers.clear();
            }
            openFile.seekg(currentPos); // Go back to previous position
        }
    }
    if (!currentLoad.jumpers.empty()) {
        planeLoads.push_back(currentLoad);
    }

    openFile.close();
}



void core::saveJumperLog() {
    
    jumperFile.close();
}

void core::savePlaneLog() {
    
    planeFile.close();
}

void core::saveDailyLog() {
    // Get current date in YYYYMMDD format
    std::time_t t = std::time(nullptr);
    std::tm tm;
    localtime_s(&tm, &t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d");
    std::string dateStr = oss.str();

    // Start with the initial filename
    std::string filename = "daily_log_" + dateStr + ".txt";
    int increment = 1;

    // If that doesn't exist, try incremented filenames
    std::ifstream infile(filename);
    while (infile.good() && increment <= 10) {
        infile.close();
        filename = "daily_log_" + dateStr + "_" + std::to_string(increment) + ".txt";
        increment++;
        infile.open(filename);
    }
    infile.close();

    // Now filename has the name of the file we want to open or it doesn't exist
    openFile.open(filename, std::ios_base::app);  // Open for writing, append mode
    if (!openFile.is_open()) {
        std::cerr << "Error: Could not open " << filename << " for writing.\n";
        return;
    }

    // Assuming that the activePlane pointer has been appropriately set
    if (activePlane != nullptr) {
        openFile << "Plane:,"
            << activePlane->name << ","
            << activePlane->seats << ","
            << activePlane->altitude << ","
            << activePlane->pilot << ","
            << activePlane->tailNumber << ","
            << activePlane->airportCode << ","
            << activePlane->timeToAltitude << ","
            << activePlane->currentLoadNum << "\n";

        // Assuming the current date/time and load number is associated with the activePlane
        openFile << "DateTime:," << activePlane->dateTime << "\n";
        openFile << "Load Number:," << activePlane->currentLoadNum << "\n";

        // Loop over all jumpers in the active plane load
        for (const auto& jumper : getJumpersFromActivePlaneLoad()) {
            openFile << jumper.id << ","
                << jumper.type << ","
                << jumper.group << "\n";
        }
        openFile << "\n"; // separating each planeLoad data with a new line
    }
    else {
        std::cerr << "Error: No active plane set.\n";
    }

    openFile.close();
}







std::string core::selectActivePlane() {
    std::string planeID;
    std::cout << "\nEnter the tail number of the plane you wish to select: ";
    std::cin >> planeID;

    bool found = false;
    for (size_t i = 0; i < planes.size(); i++) {
        if (planes[i].tailNumber == planeID) {
            activePlane = &planes[i];
            found = true;
            break;
        }
    }

    if (!found) {
        std::cerr << "Invalid plane tail number.\n";
        return ""; // Return empty string to indicate failure
    }

    return planeID;
}



void core::addJumperToActivePlane() {
    // Check if there are any planes
    if (planes.empty()) {
        std::cout << "No active plane available." << std::endl;
        return;
    }

    // Check if there are any jumpers
    if (jumpers.empty()) {
        std::cout << "No jumpers available." << std::endl;
        return;
    }

    // Display all jumpers
    std::cout << "Available jumpers:" << std::endl;
    for (const auto& jumper : jumpers) {
        std::cout << "ID: " << jumper.id << ", Name: " << jumper.name << std::endl;
    }

    // Ask the user to select a jumper based on their ID
    int jumperID;
    std::cout << "Enter the ID of the jumper you want to add to the plane: ";
    std::cin >> jumperID;

    // Find the jumper based on ID
    auto jumperIt = std::find_if(jumpers.begin(), jumpers.end(), [jumperID](const Jumper& j) {
        return j.id == jumperID;
        });

    if (jumperIt == jumpers.end()) {
        std::cout << "Invalid jumper ID." << std::endl;
        return;
    }

    // Create a JumperInfo object from the selected Jumper
    JumperInfo jumperInfo;
    jumperInfo.id = jumperIt->id;

    // Ask the user for the type of jump
    std::cout << "Select the type of jump:\n";
    std::cout << "1. Belly\n2. Free Fly\n";
    int jumpType;
    std::cin >> jumpType;
    if (jumpType == 1) {
        jumperInfo.type = "Belly";
    }
    else if (jumpType == 2) {
        jumperInfo.type = "Free Fly";
    }
    else {
        std::cout << "Invalid jump type." << std::endl;
        return;
    }

    // Ask the user for the group number
    int groupNumber;
    std::cout << "Enter the group number: ";
    std::cin >> groupNumber;
    jumperInfo.group = groupNumber;

    // Get the active plane (last plane in the list)
    Plane& activePlane = planes.back();

    // Find the PlaneLoad for the active plane
    auto it = std::find_if(planeLoads.begin(), planeLoads.end(),
        [&activePlane](const PlaneLoad& load) {
            return load.plane.tailNumber == activePlane.tailNumber;
        });

    // If the PlaneLoad for the active plane is not found, create one
    if (it == planeLoads.end()) {
        PlaneLoad newLoad;
        newLoad.plane.tailNumber = activePlane.tailNumber;
        newLoad.jumpers.push_back(jumperInfo);  // Add the jumper info to this plane
        planeLoads.push_back(newLoad);
    }
    else {
        it->jumpers.push_back(jumperInfo);  // Add the jumper info to this plane
    }

    // Optionally, remove the jumper from the jumpers list if it's a one-time assignment
    jumpers.erase(jumperIt);
}






int core::removeJumperActivePlane()
{
    int jumperID;
    std::cout << "Enter the ID of the jumper you wish to remove: ";
    std::cin >> jumperID;

    for (auto it = activeJumpers.begin(); it != activeJumpers.end(); ++it) {
        if (it->id == jumperID) {
            activeJumpers.erase(it);
            return jumperID;
        }
    }

    std::cerr << "Jumper not found on the plane.\n";
    return -1;
}





int core::checkIfPlaneFull()
{
    if (activePlane == nullptr) {
        std::cerr << "No active plane selected.\n";
        return false;
    }
    return activeJumpers.size() >= activePlane->seats;
}


int core::setTakeOffTimer()
{
    std::cout << "Enter the take-off timer in seconds: ";
    std::cin >> timer;
    return 0;  // Assuming setting timer always succeeds.
}

int core::takeOffTimer(int timervalue)
{
    timer -= timervalue;  // Decrement the timer by the given value.
    if (timer < 0) timer = 0;  // Ensure timer doesn't go negative.
    return timer;
}



int core::clearTakeOffTimer()
{
    timer = 0;
    return 0;  // Assuming clearing timer always succeeds.
}


int core::takeOffTimerCall()
{
    if (timer == 0) {
        std::cout << "Take-off time! Please proceed.\n";
        return 0;  // Timer has ended.
    }
    std::cerr << "Timer hasn't reached zero yet.\n";
    return -1;  // Timer hasn't ended.
}


int core::takeOff()
{
    if (activeJumpers.empty() || activePlane == nullptr) {
        std::cerr << "No active jumpers or plane selected.\n";
        return -1;
    }

    std::cout << "Plane " << activePlane->tailNumber << " is taking off with " << activeJumpers.size() << " jumpers.\n";
    // Clear active jumpers and plane.
    activeJumpers.clear();
    activePlane = nullptr;

    return 0;  // Successful take-off.
}


int core::weatherHold()
{
    int pauseDuration;
    std::cout << "Operations are on hold due to weather conditions.\n";
    std::cout << "Enter the duration (in minutes) for the weather hold: ";
    std::cin >> pauseDuration;

    if (pauseDuration < 0) {
        std::cerr << "Invalid duration. Hold not set.\n";
        return -1;
    }

    std::cout << "Weather hold set for " << pauseDuration << " minutes. Operations paused.\n";
    
    // Convert the input pause duration from minutes to milliseconds and sleep for that duration.
    std::this_thread::sleep_for(std::chrono::minutes(pauseDuration));
    
    std::cout << "Weather hold ended. Resuming operations.\n";
    return 0;  // Assuming always succeeds.
}


void core::exitApp()
{
    //saveJumperLog();
    //savePlaneLog();
    //saveDailyLog();
    exit(0);
}

void core::printJumper(const int index) {
    if (index < 0 || index >= jumpers.size()) {
        std::cerr << "Invalid jumper index!" << std::endl;
        return;
    }

    const Jumper& jumper = jumpers[index];

    std::cout << "Name: " << jumper.name << std::endl;
    std::cout << "ID: " << jumper.id << std::endl;
    std::cout << "License: " << jumper.licenseLetter << std::endl;
    std::cout << "First Jump: " << jumper.firstJump << std::endl;
    std::cout << "Last Jump: " << jumper.lastJump << std::endl;
    std::cout << "Total Jumps: " << jumper.totalJumps << std::endl;
}

std::string core::createNewDailyLog() {
    // Get current date in YYYYMMDD format
    std::time_t t = std::time(nullptr);
    std::tm tm;
    localtime_s(&tm, &t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d");
    std::string dateStr = oss.str();

    // Formulate initial filename
    std::string filename = "daily_log_" + dateStr + ".txt";
    int increment = 1;

    // Check if file exists, and if so, add an increment to the filename
    std::ifstream infile(filename);
    while (infile.good()) {
        infile.close();
        filename = "daily_log_" + dateStr + "_" + std::to_string(increment) + ".txt";
        increment++;
        infile.open(filename);
    }

    // Create new log file
    std::ofstream outFile(filename, std::ios::app); // Appending to ensure we don't overwrite existing data
    if (!outFile) {
        std::cerr << "Error creating new log file!\n";
        return "";
    }
    outFile.close();

    return filename;
}

std::string core::getLatestLogFile() {
    std::string dirPath = "./";  // Assuming logs are in the current directory
    std::string latestFilePath;
    std::time_t latestTime = 0;

    for (const auto& entry : fs::directory_iterator(dirPath)) {
        if (entry.is_regular_file() && entry.path().string().find(".txt") != std::string::npos) {
            // Check if the file has the required .txt extension
            std::time_t t = to_time_t_core(fs::last_write_time(entry));  // Using the conversion function here.
            if (t > latestTime) {
                latestTime = t;
                latestFilePath = entry.path().string();
            }
        }
    }
    return latestFilePath;
}

time_t core::to_time_t_core(const fs::file_time_type& ftime) {
    using namespace std::chrono;
    auto sctp = time_point_cast<system_clock::duration>(ftime - fs::file_time_type::clock::now() + system_clock::now());
    return system_clock::to_time_t(sctp);
}

std::vector<JumperInfo> core::getJumpersFromActivePlaneLoad() {
    // Check if there are any PlaneLoads available
    if (planeLoads.empty()) {
        return {}; // Return an empty vector if no plane loads.
    }

    // Get the active plane load (last plane load in the list)
    PlaneLoad& activeLoad = planeLoads.back();

    // Return the list of jumpers from the active plane load.
    return activeLoad.jumpers;
}

void core::printPlaneDetails() {
    // Ensure there are planes stored
    if (planes.empty()) {
        std::cout << "No planes available in the log." << std::endl;
        return;
    }
    for (const Plane& plane : planes) {
        std::cout << "Name: " << plane.name << ", Tail Number: " << plane.tailNumber << std::endl;
    }
}
