//Deprecated for simplicity

//#pragma once
//
//#include <string>
//#include <vector>
//#include "Skydive.h"  // Assuming Skydive class has information about each individual skydive/jumper
//
//enum class PlaneStatus {
//    OnGround,
//    InAir,
//    Maintenance
//};
//
//class Plane {
//public:
//    // Constructor with default arguments
//    Plane(const std::string& name = "", int capacity = 12, PlaneStatus status = PlaneStatus::OnGround)
//        : name(name), capacity(capacity), status(status) {}
//
//    // Getters
//    std::string getName() const { return name; }
//    int getCapacity() const { return capacity; }
//    PlaneStatus getStatus() const { return status; }
//    const std::vector<Skydive>& getCurrentLoad() const { return currentLoad; }
//
//    // Setters
//    void setName(const std::string& name) { this->name = name; }
//    void setCapacity(int capacity) { this->capacity = capacity; }
//    void setStatus(PlaneStatus status) { this->status = status; }
//
//    // Functions for interacting with the plane
//    void addJumper(const Skydive& skydive);
//    void removeJumper(int jumperId);
//    bool isFull() const;
//    void clearPlane();
//
//private:
//    std::string name;
//    int capacity;
//    PlaneStatus status;
//    std::vector<Skydive> currentLoad;
//};
//
