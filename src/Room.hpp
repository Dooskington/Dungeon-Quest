/*
    Room.hpp
    Declan Hopkins
    10/10/2015
*/

#ifndef ROOM_HPP
#define ROOM_HPP

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

#endif
