#include <iostream>
#include "Player.h"
using namespace std;
Player::Player(string name, int jersey, int salary)
{
    this->name = name;
    this->jersey = jersey;
    this->salary = salary;
}
Player::~Player(){}

Player::Player(const Player* pl)
{
    this->name = pl->name;
    this->jersey = pl->jersey;
    this->salary = pl->salary;
}

string Player::getName(){
    return name;
}

int Player::getJersey(){
    return jersey;
}

int Player::getSalary(){
    return salary;
}

void Player::setSalary(int salary) {
    Player::salary = salary;
}

void Player::setJersey(int jerseyNum) {
    Player::jersey = jerseyNum;
}

void Player::setName(string name) {
    Player::name = name;
}
