/*
    Item.cpp
    Declan Hopkins
    10/11/2015
*/

#include "Item.hpp"

Item::Item(std::string name, Type type, int power)
: m_name(name), m_type(type), m_power(power) {

}

Item::Item()
: m_name(""), m_power(0) {

}

std::string Item::getName() {
    return m_name;
}

void Item::setName(std::string newName) {
    m_name = newName;
}

Item::Type Item::getType() {
    return m_type;
}

void Item::setType(Type newType) {
    m_type = newType;
}

int Item::getPower() {
    return m_power;
}

void Item::setPower(int newPower) {
    m_power = newPower;
}
