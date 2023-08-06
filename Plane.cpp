//Deprecated for simplicity

//#include "Plane.h"
//
//// Function for adding a jumper to the plane
//void Plane::addJumper(const Skydive& skydive) {
//    if (!this->isFull()) {
//        this->currentLoad.push_back(skydive);
//    }
//    else {
//        // handle error - maybe throw an exception or print an error message
//    }
//}
//
//// Function for removing a jumper from the plane
//void Plane::removeJumper(int jumperId) {
//    for (auto load = currentLoad.begin(); load != currentLoad.end(); ++load) {
//        if (load->jumperId == jumperId) {
//            currentLoad.erase(load);
//            return;
//        }
//    }
//    // handle error - jumperId not found
//}
//
//
//// Function for checking if the plane is full
//bool Plane::isFull() const {
//    return this->currentLoad.size() >= this->capacity;
//}
//
//// Function for clearing the plane after a jump
//void Plane::clearPlane() {
//    this->currentLoad.clear();
//}
