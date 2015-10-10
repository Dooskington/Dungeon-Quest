/*
    DungeonQuest.hpp
    Declan Hopkins
    10/10/2015
*/

#ifndef DUNGEONQUEST_HPP
#define DUNGEONQUEST_HPP

#include <iostream>
#include <vector>
#include <string>

class Room {
    public:
        Room(std::string name);
        Room();

        std::string getName();
        void setName(std::string newName);
        Room* getNorth();
        void setNorth(Room* newNorth);
        Room* getSouth();
        void setSouth(Room* newSouth);
        Room* getEast();
        void setEast(Room* newEast);
        Room* getWest();
        void setWest(Room* newWest);

        void link(Room* north, Room* south, Room* east, Room* west);

    private:
        std::string m_name;
        Room* m_north;
        Room* m_south;
        Room* m_east;
        Room* m_west;
};

Room::Room(std::string name)
: m_name(name), m_north(NULL), m_south(NULL), m_east(NULL), m_west(NULL) {

}

Room::Room()
: m_name(""), m_north(NULL), m_south(NULL), m_east(NULL), m_west(NULL) {

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

void Room::link(Room* north, Room* south, Room* east, Room* west) {
    setNorth(north);
    setSouth(south);
    setEast(east);
    setWest(west);
}

#endif
