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
    // SET UP
    Room* roomEntrance = new Room("The Entrance Hall");
    Room* roomPrison = new Room("The Prison");
    Room* roomArmory = new Room("The Armory");
    Room* roomTortureChamber = new Room("The Torture Chamber");
    Room* roomCatacombs = new Room("The Catacombs");

    Item* itemShortSword = new Item("Short Sword", Item::WEAPON, 2);
    Item* itemShield = new Item("Shield", Item::ARMOR, 1);
    Item* itemHelmet = new Item("Helmet", Item::ARMOR, 2);

    roomEntrance->link(roomArmory, NULL, NULL, NULL);
    roomArmory->link(NULL, roomEntrance, roomPrison, roomTortureChamber);
    roomPrison->link(NULL, NULL, NULL, roomArmory);
    roomTortureChamber->link(roomCatacombs, NULL, roomArmory, NULL);
    roomCatacombs->link(NULL, roomTortureChamber, NULL, NULL);

    roomArmory->setItem(itemShortSword);
    roomPrison->setItem(itemShield);
    roomTortureChamber->setItem(itemHelmet);

    m_rooms.push_back(roomEntrance);
    m_rooms.push_back(roomPrison);
    m_rooms.push_back(roomArmory);
    m_rooms.push_back(roomTortureChamber);
    m_rooms.push_back(roomCatacombs);

    m_player = new Player(roomEntrance);

    // START GAME
    std::cout << "***************************" << std::endl;
    std::cout << "Welcome to Dungeon Quest!" << std::endl;
    displayLocation();

    // GAME LOOP
    std::string input;

    while(m_isRunning) {
        if(getInput(input)) {
            processInput(input);
        } else {
            std::cerr << "*** BAD INPUT ***" << std::endl;
            break;
        }
    }

    // CLEAN UP
    delete roomEntrance;
    delete roomPrison;
    delete roomArmory;
    delete roomTortureChamber;
    delete roomCatacombs;

    delete itemShortSword;
}

bool DungeonQuest::getInput(std::string& input) {
    std::cout << ">";
    bool success = getline(std::cin, input);

    return success;
}

void DungeonQuest::processInput(std::string& input) {
    if(input == "quit") {
        stop();
    } else if(input == "walk north") {
        m_player->walk("north");
        displayLocation();
    } else if(input == "walk south") {
        m_player->walk("south");
        displayLocation();
    } else if(input == "walk east") {
        m_player->walk("east");
        displayLocation();
    } else if(input == "walk west") {
        m_player->walk("west");
        displayLocation();
    } else if(input == "loot") {
        m_player->loot();
    } else if(input == "inventory") {
        m_player->displayInventory();
    }
}

void DungeonQuest::displayLocation() {
    std::cout << "***************************" << std::endl;
    std::cout << "You are in " << m_player->getLocation()->getName() << "." << std::endl;
    if(m_player->getLocation()->getNorth() != NULL) {
        std::cout << "To the north is " << m_player->getLocation()->getNorth()->getName() << "." << std::endl;
    }
    if(m_player->getLocation()->getSouth() != NULL) {
        std::cout << "To the south is " << m_player->getLocation()->getSouth()->getName() << "." << std::endl;
    }
    if(m_player->getLocation()->getEast() != NULL) {
        std::cout << "To the east is " << m_player->getLocation()->getEast()->getName() << "." << std::endl;
    }
    if(m_player->getLocation()->getWest() != NULL) {
        std::cout << "To the west is " << m_player->getLocation()->getWest()->getName() << "." << std::endl;
    }
    if(m_player->getLocation()->getItem()) {
        std::cout << "You see a " << m_player->getLocation()->getItem()->getName() << "." << std::endl;
    }
}
