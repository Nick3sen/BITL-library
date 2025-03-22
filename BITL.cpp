#include "BITL.h"

BITL::setup(const String &name, long baud) {
    _deviceName = name; // Store the provided name
    baudRate = baud; // Store the provided baud rate
    Serial.begin(baudRate); // Initialize Serial communication
    Serial.println("Library initialized with name: " + deviceName);
}
// Allows you to define to who you want to send your message, making the pi act as default and bridge
void BITL::sendPos(const String &name, int rowfrom, int heightfrom, int rowto, int heightto) {
    Serial.println(_deviceName,'move', name, rowfrom, heightfrom, rowto, heightto);
}
// Allows the gripper to send the ID of the container to the software
void BITL::sendID(const String &name, String id) {        
    Serial.println(_deviceName,'ID',name, id);
}
// Makes the crane move to the position to give the container back to the robotic arm; probably 0,0
void BITL::goSend() {
    Serial.println(_deviceName,'move',0,0,0,0);
}
// Makes the crane move to the given position where the arm placed the container; probable 0,1
void BITL::goReceive() {
    Serial.println(_deviceName,'move',1,0,0,0);
}
