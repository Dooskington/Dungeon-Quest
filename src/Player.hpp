/*
    Player.hpp
    Declan Hopkins
    10/10/2015
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Room.hpp"

class Player {
    public:
        Player(Room* location);
        Player();

        Room* getLocation();
        void setLocation(Room* newLocation);

        void walk(std::string direction);
        void loot();
        void attack();
        void displayInventory();

    private:
        std::vector<Item*> m_inventory;
        Room* m_location;
};

#endif
