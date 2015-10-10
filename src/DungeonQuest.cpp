/*
    DungeonQuest.cpp
    Declan Hopkins
    10/10/2015
*/

#include "DungeonQuest.hpp"

int main(int argc, char** argv) {
    std::vector<Room*> rooms;

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

    Player* player = new Player(roomEntrance);

    // Test
    player->walk("north");
    std::cout << "You are in: " << player->getLocation()->getName() << std::endl;
    if(player->getLocation()->getNorth() != NULL) {
        std::cout << "To the north is: " << player->getLocation()->getNorth()->getName() << std::endl;
    }
    if(player->getLocation()->getSouth() != NULL) {
        std::cout << "To the south is: " << player->getLocation()->getSouth()->getName() << std::endl;
    }
    if(player->getLocation()->getEast() != NULL) {
        std::cout << "To the east is: " << player->getLocation()->getEast()->getName() << std::endl;
    }
    if(player->getLocation()->getWest() != NULL) {
        std::cout << "To the west is: " << player->getLocation()->getWest()->getName() << std::endl;
    }

    delete roomEntrance;
    delete roomPrison;
    delete roomArmory;
    delete roomTortureChamber;
    delete roomCatacombs;
    delete player;

    return 0;
}
