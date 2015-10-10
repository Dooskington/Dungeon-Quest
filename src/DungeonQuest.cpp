/*
    DungeonQuest.cpp
    Declan Hopkins
    10/10/2015
*/

#include "DungeonQuest.hpp"

DungeonQuest::DungeonQuest()
: m_isRunning(false) {

}

DungeonQuest::~DungeonQuest() {
    // clean up
}

void DungeonQuest::start() {
    m_isRunning = true;
}

void DungeonQuest::stop() {
    m_isRunning = false;
}

void DungeonQuest::run() {
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

    m_rooms.push_back(roomEntrance);
    m_rooms.push_back(roomPrison);
    m_rooms.push_back(roomArmory);
    m_rooms.push_back(roomTortureChamber);
    m_rooms.push_back(roomCatacombs);

    m_player = new Player(roomEntrance);

    while(m_isRunning) {
        m_player->walk("north");
        std::cout << "You are in: " << m_player->getLocation()->getName() << std::endl;
        if(m_player->getLocation()->getNorth() != NULL) {
            std::cout << "To the north is: " << m_player->getLocation()->getNorth()->getName() << std::endl;
        }
        if(m_player->getLocation()->getSouth() != NULL) {
            std::cout << "To the south is: " << m_player->getLocation()->getSouth()->getName() << std::endl;
        }
        if(m_player->getLocation()->getEast() != NULL) {
            std::cout << "To the east is: " << m_player->getLocation()->getEast()->getName() << std::endl;
        }
        if(m_player->getLocation()->getWest() != NULL) {
            std::cout << "To the west is: " << m_player->getLocation()->getWest()->getName() << std::endl;
        }

        stop();
    }

    delete roomEntrance;
    delete roomPrison;
    delete roomArmory;
    delete roomTortureChamber;
    delete roomCatacombs;
}
