/*
    DungeonQuest.cpp
    Declan Hopkins
    10/10/2015
*/

#include "DungeonQuest.hpp"

int main(int argc, char** argv) {
    std::vector<Room*> rooms;
    Room* currentRoom;

    Room* roomEntrance = new Room("Dungeon Entrance");
    Room* roomPrison = new Room("Prison");
    Room* roomArmory = new Room("Armory");
    Room* roomTortureChamber = new Room("Torture Chamber");
    Room* roomCatacombs = new Room("Catacombs");

    roomEntrance->link(roomPrison, NULL, NULL, NULL);
    roomPrison->link(NULL, roomEntrance, roomArmory, roomTortureChamber);
    roomArmory->link(NULL, NULL, NULL, roomPrison);
    roomTortureChamber->link(roomCatacombs, NULL, roomPrison, NULL);
    roomCatacombs->link(NULL, roomTortureChamber, NULL, NULL);

    rooms.push_back(roomEntrance);
    rooms.push_back(roomPrison);
    rooms.push_back(roomArmory);
    rooms.push_back(roomTortureChamber);
    rooms.push_back(roomCatacombs);

    // Test
    currentRoom = roomPrison;
    std::cout << "You are in: " << currentRoom->getName() << std::endl;
    if(currentRoom->getNorth() != NULL) {
        std::cout << "To the north is: " << currentRoom->getNorth()->getName() << std::endl;
    }
    if(currentRoom->getSouth() != NULL) {
        std::cout << "To the south is: " << currentRoom->getSouth()->getName() << std::endl;
    }
    if(currentRoom->getEast() != NULL) {
        std::cout << "To the east is: " << currentRoom->getEast()->getName() << std::endl;
    }
    if(currentRoom->getWest() != NULL) {
        std::cout << "To the west is: " << currentRoom->getWest()->getName() << std::endl;
    }

    delete roomEntrance;
    delete roomPrison;
    delete roomArmory;
    delete roomTortureChamber;
    delete roomCatacombs;

    return 0;
}
