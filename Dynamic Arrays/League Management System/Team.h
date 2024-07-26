#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED
#include "Player.h"
using namespace std;
class Team
{
public:
    Player** players;
    Team( string name,int founding);
    Team( const Team* team);
    ~Team();
    string getName();
    void setName(const string name);
    int getYear();
    void setYear(const int founding);
    int getPlayerCount();
    void setPlayerCount(const int playerCount);

private:
    string name;
    int founding;
    int playerCount;
};
#endif // TEAM_H_INCLUDED
