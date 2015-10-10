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
        }
    } else if(direction == "south") {
        if(m_location->getSouth()) {
            m_location = m_location->getSouth();
        }
    } else if(direction == "east") {
        if(m_location->getEast()) {
            m_location = m_location->getEast();
        }
    } else if(direction == "west") {
        if(m_location->getWest()) {
            m_location = m_location->getWest();
        }
    } else {
        std::cerr << "Invalid direction!" << std::endl;
    }
}