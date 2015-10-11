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
