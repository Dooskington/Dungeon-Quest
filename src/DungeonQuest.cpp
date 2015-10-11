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
    Room* roomEntrance = new Room("The Entrance Hall");
    Room* roomPrison = new Room("The Prison");
    Room* roomArmory = new Room("The Armory");
    Room* roomTortureChamber = new Room("The Torture Chamber");
    Room* roomCatacombs = new Room("The Catacombs");

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

    // The line of input
    std::string input;

    // While the input is valid
    // Get new input
    while(processInput(input)) {
        if(input == "quit") {
            break;
        } else if(input == "walk north") {
            m_player->walk("north");
        } else if(input == "walk south") {
            m_player->walk("south");
        } else if(input == "walk east") {
            m_player->walk("east");
        } else if(input == "walk west") {
            m_player->walk("west");
        }

        displayLocation();
    }

    delete roomEntrance;
    delete roomPrison;
    delete roomArmory;
    delete roomTortureChamber;
    delete roomCatacombs;

    stop();
}

bool DungeonQuest::processInput(std::string& input) {
    std::cout << ">";
    bool success = getline(std::cin, input);

    return success;
}

void DungeonQuest::displayLocation() {
    std::cout << "You are in " << m_player->getLocation()->getName() << "." << std::endl;
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
}
