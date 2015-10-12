/*
    Player.cpp
    Declan Hopkins
    10/10/2015
*/

#include "Player.hpp"

Player::Player(Room* location)
: m_location(location) {

}

Player::Player()
: m_location(NULL) {

}

Room* Player::getLocation() {
    return m_location;
}

void Player::setLocation(Room* newLocation) {
    m_location = newLocation;
}

void Player::walk(std::string direction) {
    if(direction == "north") {
        if(m_location->getNorth()) {
            m_location = m_location->getNorth();
            std::cout << "You walk north." << std::endl;
        } else {
            std::cout << "You cannot walk in that direction." << std::endl;
        }
    } else if(direction == "south") {
        if(m_location->getSouth()) {
            m_location = m_location->getSouth();
            std::cout << "You walk south." << std::endl;
        } else {
            std::cout << "You cannot walk in that direction." << std::endl;
        }
    } else if(direction == "east") {
        if(m_location->getEast()) {
            m_location = m_location->getEast();
            std::cout << "You walk east." << std::endl;
        } else {
            std::cout << "You cannot walk in that direction." << std::endl;
        }
    } else if(direction == "west") {
        if(m_location->getWest()) {
            m_location = m_location->getWest();
            std::cout << "You walk west." << std::endl;
        } else {
            std::cout << "You cannot walk in that direction." << std::endl;
        }
    } else {
        std::cerr << "Invalid direction!" << std::endl;
    }
}

void Player::loot() {
    if(m_location->getItem()) {
        Item* item = m_location->getItem();
        m_inventory.push_back(item);
        m_location->setItem(NULL);
        std::cout << "You aquire a " << item->getName() << "." << std::endl;
    } else {
        std::cout << "There is nothing here to loot." << std::endl;
    }
}

void Player::displayInventory() {
    std::cout << "You open up your backpack." << std::endl;
    std::cout << "Inside, you find ";
    if(m_inventory.size() == 0) {
        std::cout << "nothing." << std::endl;
    } else {
        for(std::vector<Item*>::const_iterator it = m_inventory.begin(); it != m_inventory.end(); ++it) {
            if(m_inventory.size() > 1 && it + 1 == m_inventory.end()) {
                std::cout << "and ";
            }
            std::cout << "a " << (*it)->getName();
            if(it + 1 != m_inventory.end()) {
                std::cout << ", ";
            } else {
                std::cout << "." << std::endl;
            }
        }
    }
}
