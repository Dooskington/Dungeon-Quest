/*
    DungeonQuest.hpp
    Declan Hopkins
    10/10/2015
*/

#ifndef DUNGEONQUEST_HPP
#define DUNGEONQUEST_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include "Player.hpp"
#include "Room.hpp"
#include "Item.hpp"

class DungeonQuest {
    public:
        DungeonQuest();
        ~DungeonQuest();

        void start();
        void run();
        void stop();

        bool getInput(std::string& input);
        void processInput(std::string& input);
        void splitInput(std::string& input, std::string& cmd, std::string& arg);
        std::vector<std::string> split(const std::string& str);
        void displayLocation();

    private:
        std::vector<Room*> m_rooms;
        Player* m_player;
        bool m_isRunning;
};

#endif
