/*
    Room.cpp
    Declan Hopkins
    10/10/2015
*/

#include "Room.hpp"

Room::Room(std::string name)
: m_name(name), m_north(NULL), m_south(NULL), m_east(NULL), m_west(NULL), m_item(NULL) {

}

Room::Room()
: m_name(""), m_north(NULL), m_south(NULL), m_east(NULL), m_west(NULL), m_item(NULL) {

}

std::string Room::getName() {
    return m_name;
}

void Room::setName(std::string newName) {
    m_name = newName;
}

Room* Room::getNorth() {
    return m_north;
}

void Room::setNorth(Room* newNorth) {
    m_north = newNorth;
}

Room* Room::getSouth() {
    return m_south;
}

void Room::setSouth(Room* newSouth) {
    m_south = newSouth;
}

Room* Room::getEast() {
    return m_east;
}

void Room::setEast(Room* newEast) {
    m_east = newEast;
}

Room* Room::getWest() {
    return m_west;
}

void Room::setWest(Room* newWest) {
    m_west = newWest;
}

Item* Room::getItem() {
    return m_item;
}

void Room::setItem(Item* newItem) {
    m_item = newItem;
}

void Room::link(Room* north, Room* south, Room* east, Room* west) {
    setNorth(north);
    setSouth(south);
    setEast(east);
    setWest(west);
}
