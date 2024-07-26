#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
using namespace std;
class Player{
public:
    Player(string name, int jersey, int salary);
    Player(const Player* pl);
    ~Player();

    string getName();
    void setName( string name );

    int getJersey();
    void setJersey( int jerseyNum );

    int getSalary();
    void setSalary( int salary );
private:
    string name;
    int jersey;
    int salary;

};

#endif // PLAYER_H_INCLUDED