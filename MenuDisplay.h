#pragma once
#include "core.h"
#include <filesystem>


namespace fs = std::filesystem;

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

enum class DisplayError {
    badInput,
    newLogCreated
};


class MenuDisplay
{
public:
    MenuDisplay(core& myCore)
        : menuOption(MenuOptions::undefined), myCore(myCore), timerValue(0), option(0) {}

    int startMenu();
    int mainMenu();
    int createPlaneMenu();
    int newLoadMenu();
    int createJumperMenu();
    int editLogMenu();
    int editDaily();
    int editJumper();
    int editPlane();
    void closeDayMenu();

    MenuOptions getMenuOption() const { return menuOption; }
    void setMenuOption(MenuOptions option) { menuOption = option; }

    int getTimerValue() const { return timerValue; }
    void setTimerValue(int value) { timerValue = value; }

    void updateMenu(MenuOptions menuOption);
    void clearScreen();

    time_t to_time_t(const fs::file_time_type& ftime) {
        using namespace std::chrono;
        auto sctp = time_point_cast<system_clock::duration>(ftime - fs::file_time_type::clock::now() + system_clock::now());
        return system_clock::to_time_t(sctp);
    }

private:
    MenuOptions menuOption;
    DisplayError displayError;
    core& myCore;
    int timerValue;
    int option;
    std::fstream openFile;
    std::fstream jumperFile;
    std::fstream planeFile;
    std::string activeTailNumber;
    int junk;
};
