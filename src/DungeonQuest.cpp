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

    Monster* monsterZombie = new Monster("Zombie", 5, 1);
    Monster* monsterGhost = new Monster("Ghost", 10, 2);

    roomEntrance->link(roomArmory, NULL, NULL, NULL);
    roomArmory->link(NULL, roomEntrance, roomPrison, roomTortureChamber);
    roomPrison->link(NULL, NULL, NULL, roomArmory);
    roomTortureChamber->link(roomCatacombs, NULL, roomArmory, NULL);
    roomCatacombs->link(NULL, roomTortureChamber, NULL, NULL);

    roomArmory->setItem(itemShortSword);
    roomPrison->setItem(itemShield);
    roomTortureChamber->setItem(itemHelmet);

    roomArmory->setMonster(monsterZombie);
    roomCatacombs->setMonster(monsterGhost);

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

    // Player
    delete m_player;

    // Rooms
    delete roomEntrance;
    delete roomPrison;
    delete roomArmory;
    delete roomTortureChamber;
    delete roomCatacombs;

    // Items
    delete itemShortSword;
    delete itemShield;
    delete itemHelmet;

    // Monsters
    delete monsterZombie;
    delete monsterGhost;
}

bool DungeonQuest::getInput(std::string& input) {
    std::cout << ">";
    bool success = getline(std::cin, input);

    return success;
}

void DungeonQuest::processInput(std::string& input) {
    std::string cmd;
    std::string arg;
    splitInput(input, cmd, arg);

    if(cmd == "quit") {
        stop();
        return;
    }

    if(cmd == "walk") {
        m_player->walk(arg);
        displayLocation();
    }

    if(cmd == "loot") {
        m_player->loot();
    }

    if(cmd == "inventory") {
        m_player->displayInventory();
    }

    if(cmd == "attack") {
        m_player->attack();
    }
}

// TODO
// Make input safer
void DungeonQuest::splitInput(std::string& input, std::string& cmd, std::string& arg) {
    std::vector<std::string> inputs = split(input);
    if(inputs.size() > 0) {
        cmd = inputs[0];
        if(inputs.size() > 1) {
            arg = inputs[1];
        }
    }
}

// TODO
// Do something with these random functions
bool space(char c) {
    return isspace(c);
}

bool notSpace(char c) {
    return !isspace(c);
}

// TODO
// Rewrite without std algorithms
std::vector<std::string> DungeonQuest::split(const std::string& str) {
    std::vector<std::string> ret;
    std::string::const_iterator i = str.begin();
    std::string::const_iterator j;
    while(i != str.end()) {
        i = find_if(i, str.end(), notSpace);
        j = find_if(i, str.end(), space);

        if(i != str.end()) {
            ret.push_back(std::string(i, j));
        }

        i = j;
    }

    return ret;
}

void DungeonQuest::displayLocation() {
    Room* location = m_player->getLocation();
    std::cout << "***************************" << std::endl;
    std::cout << "You are in " << m_player->getLocation()->getName() << "." << std::endl;

    if(location->getNorth() != NULL) {
        std::cout << "To the north is " << location->getNorth()->getName() << "." << std::endl;
    }

    if(location->getSouth() != NULL) {
        std::cout << "To the south is " << location->getSouth()->getName() << "." << std::endl;
    }

    if(location->getEast() != NULL) {
        std::cout << "To the east is " << location->getEast()->getName() << "." << std::endl;
    }

    if(location->getWest() != NULL) {
        std::cout << "To the west is " << location->getWest()->getName() << "." << std::endl;
    }

    if(location->getItem()) {
        std::cout << "There is a " << location->getItem()->getName() << " on the ground." << std::endl;
    }

    if(location->getMonster()) {
        std::cout << "You see a " << location->getMonster()->getName();
        if(location->getMonster()->isAlive()) {
            std::cout << "!" << std::endl;
        } else {
            std::cout << " carcass." << std::endl;
        }
    }
}
