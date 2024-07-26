#include <iostream>
#include "Team.h"
using namespace std;

Team::Team(string name,int founding){
    playerCount = 0;
    players = NULL;
    this->name = name;
    this->founding = founding;
}

Team::~Team(){
    for(int i = 0; i < playerCount && players != NULL; i++ )
    {
        delete players[i];
        players[i] = NULL;
    }
    delete[] players;
    players = NULL;
}

Team::Team(const Team* team){
    if(this != team){
        this->players = NULL;
        this->name = team->name;
        this->founding = team->founding;
        this->playerCount = team->playerCount;
        if(team->playerCount != 0){
            this->players = new Player*[team->playerCount];
            for(int i = 0; i< team->playerCount; i++){
                this->players[i] = new Player(team->players[i]);
            }
        }
    }
}

string Team::getName(){
    return name;
}

int Team::getYear(){
    return founding;
}

int Team::getPlayerCount(){
    return playerCount;
}

void Team::setYear(const int founding) {
    this->founding = founding;
}

void Team::setName(const string name) {
    this->name = name;
}

void Team::setPlayerCount(const int playerCount) {
    this->playerCount = playerCount;
}
