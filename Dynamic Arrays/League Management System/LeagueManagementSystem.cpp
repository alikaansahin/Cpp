#include <iostream>
#include "LeagueManagementSystem.h"
#include "Team.h"
#include "Player.h"
using namespace std;

//Constructor
LeagueManagementSystem::LeagueManagementSystem()
{
    teamArrSize = 0;
    teamArr = NULL;

}
//Destructor
LeagueManagementSystem::~LeagueManagementSystem()
{

    for(int i = 0; i < teamArrSize; i++)
    {
        delete [] teamArr[i];
        teamArr[i] = NULL;
    }
    delete[] teamArr;
    teamArr = NULL;
}

void LeagueManagementSystem::addTeam( const string name, const int year ){
    if(teamArr == NULL){
        teamArr = new Team*[1];
        teamArr[teamArrSize] = new Team(name, year);
        teamArrSize++;
        cout<<"Added team "<< name <<"."<<endl;
        return;
    }
    else{
        for(int i = 0; i < teamArrSize; i++){
            if(name == teamArr[i]->getName())
            {
                cout << "Cannot add team. Team " << name << " already exists." << endl;
                return;
            }
        }
        Team** tempArr = new Team*[teamArrSize];

        for (int i = 0; i < teamArrSize; i++){
            tempArr[i] = new Team(teamArr[i]);
        }

        for(int i = 0; i < teamArrSize; i++){
            delete teamArr[i];
            teamArr[i] = NULL;
        }
        delete[] teamArr;
        teamArr = NULL;


        teamArr = new Team*[teamArrSize + 1];
        for (int i = 0; i < teamArrSize ; i++){
            teamArr[i] = new Team(tempArr[i]);
        }
        for(int i = 0; i < teamArrSize -1; i++){
            delete tempArr[i];
            tempArr[i] = NULL;
        }
        delete [] tempArr;
        tempArr = NULL;
    }

    teamArr[teamArrSize] = new Team(name, year);
    teamArrSize++;
    cout<<"Added team "<< name <<"."<<endl;
}

void LeagueManagementSystem::removeTeam( const string name )
{
    bool isExist = false;
    int index = 0;

    for(int i = 0; i < teamArrSize; i++){
        if (name == teamArr[i]->getName())
        {
            isExist = true;
            index = i;
            break;
        }
    }

    if(!isExist){
        cout <<"Cannot remove team. Team " << name << " does not exist."<<endl;
        return;
    }
    else{
        Team** temp = new Team*[teamArrSize - 1];

        for(int i = 0; i < teamArrSize - 1; i++){
            temp[i] = NULL;
        }

        int tempIndex = 0;

        for (int playerIndex = 0; playerIndex < teamArr[index]->getPlayerCount(); playerIndex++)
        {
            delete teamArr[index]->players[playerIndex];
            teamArr[index]->players[playerIndex] = NULL;
        }
        delete [] teamArr[index]->players;
        teamArr[index]->players = NULL;
        delete teamArr[index];
        teamArr[index] = NULL;


        for(int teamIndex=0; teamIndex < teamArrSize; teamIndex++){

            if(teamArr[teamIndex] != NULL)
            {
                temp[tempIndex] = new Team(teamArr[teamIndex]);
                tempIndex++;
                delete teamArr[teamIndex];
                teamArr[teamIndex] = NULL;
            }
        }
        delete [] teamArr;
        teamArr = NULL;

        teamArrSize--;
        teamArr = new Team*[teamArrSize];

        for(int teamIndex=0; teamIndex < teamArrSize; teamIndex++){
            if(temp[teamIndex]!=NULL)
                teamArr[teamIndex] = new Team(temp[teamIndex]);
        }

        for(int tempIndex = 0; tempIndex < teamArrSize; tempIndex++){
            delete temp[tempIndex];
            temp[tempIndex] = NULL;
        }

        delete [] temp;
        temp = NULL;

        cout<<"Removed team "<<name<<"."<<endl;
    }
}

void LeagueManagementSystem::addPlayer( const string teamName, const string playerName, const int jersey, const int salary ) {
    bool teamExist = false;
    int teamIndex;
    for (int i = 0; !teamExist && i < teamArrSize; i++) {
        if (teamName == teamArr[i]->getName()) {
            teamExist = true;
            teamIndex = i;
            for (int j = 0; j < teamArr[teamIndex]->getPlayerCount(); j++) {
                if (teamArr[teamIndex]->players[j]->getJersey() == jersey) {
                    cout << "Cannot add player. Jersey number " << jersey << " already exists in team " << teamName <<"." <<endl;
                    return;
                }
            }
            //creating temp array
            Player **tempPlayerArray = NULL;
            if (teamArr[teamIndex]->players != NULL) {

                tempPlayerArray = new Player *[teamArr[teamIndex]->getPlayerCount()];

                for (int i = 0; i < teamArr[teamIndex]->getPlayerCount(); i++) {
                    tempPlayerArray[i] = new Player(teamArr[teamIndex]->players[i]);
                }
                for (int i = 0; i < teamArr[teamIndex]->getPlayerCount(); i++) {
                    delete teamArr[teamIndex]->players[i];
                    teamArr[teamIndex]->players[i] = NULL;
                }
                delete[] teamArr[teamIndex]->players;
                teamArr[teamIndex]->players = NULL;
            }
            teamArr[teamIndex]->players = new Player *[teamArr[teamIndex]->getPlayerCount() + 1];
            if (tempPlayerArray != NULL) {
                for (int i = 0; i < teamArr[teamIndex]->getPlayerCount(); i++) {
                    teamArr[teamIndex]->players[i] = new Player(tempPlayerArray[i]);
                }
                for (int i = 0; i < teamArr[teamIndex]->getPlayerCount(); i++) {
                    delete tempPlayerArray[i];
                    tempPlayerArray[i] = NULL;
                }
                delete[] tempPlayerArray;
                tempPlayerArray = NULL;
            }
            teamArr[teamIndex]->players[teamArr[teamIndex]->getPlayerCount()] = new Player(playerName, jersey, salary);
            teamArr[teamIndex]->setPlayerCount(teamArr[teamIndex]->getPlayerCount() + 1);

            cout << "Added player " << playerName << " to team " << teamName << "." << endl;
            return;
        }
    }
    cout << "Cannot add player. Team " << teamName << " does not exist." <<endl;
    return;

}
void LeagueManagementSystem::removePlayer( const string teamName, const string playerName )
{
    int a = 0;
    int b = 0;
    bool teamExist = false;
    bool playerExist = false;
    //finding if team exists
    for(int i = 0; i < teamArrSize; i++)
    {
        if(teamArr[i]->getName() == teamName)
        {
            a = i;
            teamExist = true;
            break;
        }
    }
    if(!teamExist){
        cout << "Cannot remove player. Team " << teamName <<" does not exist." << endl;
        return;
    }
    //finding if player exists
    for(int i = 0; i < teamArr[a]->getPlayerCount(); i++)
    {
        if(teamArr[a]->players[i]->getName() == playerName)
        {
            b = i;
            playerExist = true;
            break;
        }
    }
    if(!playerExist){
        cout << "Cannot remove player. Player " << playerName <<" does not exist." << endl;
        return;
    }
    //creating temp array
    Player **tempPlayerArr = new Player*[teamArr[a]->getPlayerCount() - 1];
    for(int i = 0; i < b ;i++){
        tempPlayerArr[i] = new Player(teamArr[a]->players[i]);
    }
    for(int i = b + 1 ; i < teamArr[a]->getPlayerCount() ;i++){
        tempPlayerArr[i] = teamArr[a]->players[i];
    }
    for(int i = 0; i < teamArr[a]->getPlayerCount(); i++ ){
        delete teamArr[a]->players[i];
        teamArr[a]->players[i] = NULL;
    }
    delete [] teamArr[a]->players;
    teamArr[a]->players = NULL;

    //creating new player array within a team array
    teamArr[a]->players = new Player*[teamArr[a]->getPlayerCount() - 1];
    for(int i  =0; i < teamArr[a]->getPlayerCount() - 1; i++){
        teamArr[a]->players[i] = new Player(tempPlayerArr[i]);
    }
    for(int i = 0; i < teamArr[a]->getPlayerCount() - 1; i++ ){
        delete tempPlayerArr[i];
        tempPlayerArr[i] = NULL;
    }
    delete [] tempPlayerArr;
    tempPlayerArr = NULL;
    teamArr[a]->setPlayerCount(teamArr[a]->getPlayerCount() -1);
    cout << "Removed player " << playerName << " from team " << teamName <<"."<< endl;

}

void LeagueManagementSystem::transferPlayer( const string playerName, const string departTeamName, const string arriveTeamName ) {
    int jersey = 0;
    int salary = 0;
    int departTeamIndex = 0;
    int departPlayerIndex = 0;
    int arriveTeamIndex = 0;
    bool departTeamExist = false;
    bool arriveTeamExist = false;
    bool playerExist = false;
    bool jerseyExist = false;

    //finding out if depart team exist
    for(int i = 0; i < teamArrSize; i++)
    {
        if(teamArr[i]->getName() == departTeamName)
        {
            departTeamIndex = i;
            departTeamExist = true;
        }
    }
    //finding out if arrive team exist
    for(int i = 0; i < teamArrSize; i++)
    {
        if (teamArr[i]->getName() == arriveTeamName)
        {
            arriveTeamIndex = i;
            arriveTeamExist = true;
        }
    }
    if(!departTeamExist){
        cout << "Cannot transfer player. Team " << departTeamName <<" does not exist." << endl;
        return;
    }
    if(!arriveTeamExist){
        cout << "Cannot transfer player. Team " << arriveTeamName <<" does not exist." << endl;
        return;
    }

    //finding out if player is exist in specified team with index: "departTeamIndex"
    for(int i = 0; i < teamArr[departTeamIndex]->getPlayerCount(); i++)
    {
        if(teamArr[departTeamIndex]->players[i]->getName() == playerName)
        {
            //finding the player index of the player to be removed
            departPlayerIndex = i;
            playerExist = true;
            break;
        }
    }

    if(!playerExist){
        cout << "Cannot transfer player. Player " << playerName <<" does not exist." << endl;
        return;
    }

    //looking the jersey number in arrive team. If it exists player won't be added
    for(int i = 0; i < teamArr[arriveTeamIndex]->getPlayerCount(); i++)
    {
        if (teamArr[arriveTeamIndex]->players[i]->getJersey() == teamArr[departTeamIndex]->players[departPlayerIndex]->getJersey())
        {
            jerseyExist = true;
            break;
        }
    }

    if(jerseyExist){
        cout << "Cannot transfer player. Jersey number "<< teamArr[departTeamIndex]->players[departPlayerIndex]->getJersey()
             << " already exists in team " << arriveTeamName << "." << endl;
        return;
    }
    //getting salary and jersey info of the player from the depart team
    salary = teamArr[departTeamIndex]->players[departPlayerIndex]->getSalary();
    jersey = teamArr[departTeamIndex]->players[departPlayerIndex]->getJersey();

    //addPlayer
    Player **tempPlayerArray = NULL;

    tempPlayerArray = new Player *[teamArr[arriveTeamIndex]->getPlayerCount()];

    for (int i = 0; i < teamArr[arriveTeamIndex]->getPlayerCount(); i++) {
        tempPlayerArray[i] = new Player(teamArr[arriveTeamIndex]->players[i]);
    }
    for (int i = 0; i < teamArr[arriveTeamIndex]->getPlayerCount(); i++) {
        delete teamArr[arriveTeamIndex]->players[i];
        teamArr[arriveTeamIndex]->players[i] = NULL;
    }
    delete[] teamArr[arriveTeamIndex]->players;
    teamArr[arriveTeamIndex]->players = NULL;

    teamArr[arriveTeamIndex]->players = new Player *[teamArr[arriveTeamIndex]->getPlayerCount() + 1];

    if (tempPlayerArray != NULL) {
        for (int i = 0; i < teamArr[arriveTeamIndex]->getPlayerCount(); i++) {
            teamArr[arriveTeamIndex]->players[i] = new Player(tempPlayerArray[i]);
        }
        for (int i = 0; i < teamArr[arriveTeamIndex]->getPlayerCount(); i++) {
            delete tempPlayerArray[i];
            tempPlayerArray[i] = NULL;
        }
        delete[] tempPlayerArray;
        tempPlayerArray = NULL;
    }

    teamArr[arriveTeamIndex]->players[teamArr[arriveTeamIndex]->getPlayerCount()] = new Player(playerName, jersey, salary);

    teamArr[arriveTeamIndex]->setPlayerCount(teamArr[arriveTeamIndex]->getPlayerCount() + 1);

    //removePlayer
    Player **tempPlayerArr = new Player*[teamArr[departTeamIndex]->getPlayerCount() - 1];
    for(int i = 0; i < departPlayerIndex ;i++){
        tempPlayerArr[i] = new Player(teamArr[departTeamIndex]->players[i]);
    }
    for(int i = departPlayerIndex + 1 ; i < teamArr[departTeamIndex]->getPlayerCount() ;i++){
        tempPlayerArr[i - 1] = new Player(teamArr[departTeamIndex]->players[i]);
    }
    for(int i = 0; i < teamArr[departTeamIndex]->getPlayerCount(); i++ ){
        delete teamArr[departTeamIndex]->players[i];
        teamArr[departTeamIndex]->players[i] = NULL;
    }

    delete [] teamArr[departTeamIndex]->players;
    teamArr[departTeamIndex]->players = NULL;

    teamArr[departTeamIndex]->players = new Player*[teamArr[departTeamIndex]->getPlayerCount() - 1];

    for(int i  =0; i < teamArr[departTeamIndex]->getPlayerCount() - 1; i++){
        teamArr[departTeamIndex]->players[i] = new Player(tempPlayerArr[i]);
    }

    for(int i = 0; i < teamArr[departTeamIndex]->getPlayerCount() - 1; i++ ){
        delete tempPlayerArr[i];
        tempPlayerArr[i] = NULL;
    }

    delete [] tempPlayerArr;
    tempPlayerArr = NULL;

    teamArr[departTeamIndex]->setPlayerCount(teamArr[departTeamIndex]->getPlayerCount() -1);

    cout << "Transferred player " << playerName << " from team " <<departTeamName<< " to team " <<arriveTeamName<<"."<<endl;

}
void LeagueManagementSystem::showAllTeams() const
{
    cout << "Teams in the league management system:" <<endl;
    if(teamArrSize == 0)
    {
        cout<<"None"<<endl;
    }
    for(int team = 0; team < teamArrSize; team++)
    {
        int totalSalary = 0;
        for(int player = 0; player < teamArr[team]->getPlayerCount(); player++)
        {
            totalSalary += teamArr[team]->players[player]->getSalary();
        }
        cout<<teamArr[team]->getName();
        cout<<", "<<teamArr[team]->getYear();
        cout<<", "<<teamArr[team]->getPlayerCount()<<" players, ";
        cout<<totalSalary<<" TL total salary";
        cout<<endl;
    }

}
void LeagueManagementSystem::showTeam( const string name ) const
{
    int totalSalary = 0;
    int team = 0;
    bool isExist = false;
    for(int i = 0 ; i < teamArrSize ; i++)
    {
        if(name == teamArr[i]->getName()) {
            team = i;
            isExist = true;
            break;
        }
    }
    if(!isExist)
    {
        cout<<"Team "<<name<<" does not exist."<<endl;
        return;
    }
    for(int player = 0; player < teamArr[team]->getPlayerCount(); player++)
    {
        totalSalary += teamArr[team]->players[player]->getSalary();
    }
    cout<<"Team: "<<endl ;
    cout<<teamArr[team]->getName();
    cout<<", "<<teamArr[team]->getYear();
    cout<<", "<<teamArr[team]->getPlayerCount()<<" players, ";
    cout<<totalSalary<<" TL total salary " <<endl;
    cout<<"Players:"<<endl;

    for(int i = 0; i < teamArr[team]->getPlayerCount(); i++)
    {
        cout<<teamArr[team]->players[i]->getName();
        cout<<", jersey "<<teamArr[team]->players[i]->getJersey();
        cout<<", "<<teamArr[team]->players[i]->getSalary()<<" TL salary "<<endl;
    }

}
void LeagueManagementSystem::showPlayer( const string name ) const
{
    int team = 0;
    int player = 0;
    bool isExist = false;
    for(team ; team < teamArrSize; team++)
    {
        for(player ; player < teamArr[team]->getPlayerCount(); player++)
        {
            if(name == teamArr[team]->players[player]->getName())
            {
                isExist = true;
                break;
            }
        }
        if(isExist) break;
    }
    if(!isExist)
    {
        cout<<"Player "<<name<<" does not exist."<<endl;
        return;
    }
    else
    {
        cout << "Player: " << endl;
        cout << teamArr[team]->players[player]->getName()<<", jersey "<<
             teamArr[team]->players[player]->getJersey()<<", "<<
             teamArr[team]->players[player]->getSalary()
             <<" TL salary"<<endl<<"Plays in team "<<teamArr[team]->getName()<<"."<<endl;
    }
}