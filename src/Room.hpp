/*
    Room.hpp
    Declan Hopkins
    10/10/2015
*/

#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include "Item.hpp"
#include "Monster.hpp"

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
        Item* getItem();
        void setItem(Item* newItem);
        Monster* getMonster();
        void setMonster(Monster* newMonster);

        void link(Room* north, Room* south, Room* east, Room* west);

    private:
        std::string m_name;
        Room* m_north;
        Room* m_south;
        Room* m_east;
        Room* m_west;
        Item* m_item;
        Monster* m_monster;
};

#endif
