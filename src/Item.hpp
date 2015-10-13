/*
    Item.hpp
    Declan Hopkins
    10/11/2015
*/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item {
    public:
        enum Type {WEAPON, ARMOR, HEALTH};

        Item(std::string name, Type type, int power);
        Item();

        std::string getName();
        void setName(std::string newName);
        Type getType();
        void setType(Type newType);
        int getPower();
        void setPower(int newPower);

    private:
        std::string m_name;
        Type m_type;
        int m_power;
};      

#endif
