#include <iostream>
using namespace std;
#include "LeagueManagementSystem.h"
int main() {
    LeagueManagementSystem LMS;


    //Simple Transfer Check
    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);

    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.showAllTeams();
    LMS.showPlayer("p1");
    LMS.showTeam("t2");

    LMS.removePlayer("t1", "p1");
    LMS.addPlayer("t2", "p3", 1,1);

    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    cout<<endl;

    //Multiple Transfers

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);

    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.addPlayer("t1", "p2", 2, 2);
    LMS.addPlayer("t1", "p3", 3, 3);

    LMS.transferPlayer("p1", "t1", "t2");
    LMS.transferPlayer("p2", "t1", "t2");
    LMS.transferPlayer("p3", "t1", "t2");

    LMS.removePlayer("t1", "p1");
    LMS.removePlayer("t1", "p2");
    LMS.removePlayer("t1", "p3");

    LMS.addPlayer("t1", "p11", 1, 1);
    LMS.addPlayer("t1", "p12", 2, 2);
    LMS.addPlayer("t1", "p13", 3, 3);

    LMS.addPlayer("t2", "p21", 1, 1);
    LMS.addPlayer("t2", "p22", 2, 2);
    LMS.addPlayer("t2", "p23", 3, 3);

    LMS.showAllTeams();
    LMS.showPlayer("p1");
    LMS.showPlayer("p2");
    LMS.showPlayer("p3");
    LMS.showTeam("t1");
    LMS.showTeam("t2");
    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    cout<<endl;

    //Transfer Cycle

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addTeam("t3", 13);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.addPlayer("t1", "p2", 2, 1);
    LMS.addPlayer("t2", "p3", 2, 1);
    LMS.addPlayer("t3", "p4", 2, 1);

    LMS.transferPlayer("p1", "t1", "t2");
    LMS.showPlayer("p1");
    LMS.transferPlayer("p1", "t2", "t3");
    LMS.showPlayer("p1");
    LMS.transferPlayer("p1", "t3", "t1");
    LMS.showPlayer("p1");
    LMS.showAllTeams();

    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    LMS.removeTeam("t3");
    cout<<endl;

    // Jersey
    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.addPlayer("t2", "p2", 1, 1);
    LMS.transferPlayer("p1", "t1", "t2");

    LMS.showPlayer("p1");

    LMS.removePlayer("t2", "p2");
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.showPlayer("p1");
    LMS.addPlayer("t2", "p3", 1,1);
    LMS.removePlayer("t2", "p1");
    LMS.addPlayer("t2", "p3", 1,1);
    LMS.showPlayer("p1");
    LMS.showPlayer("p2");
    LMS.showPlayer("p3");
    LMS.removeTeam("t1");
    LMS.removeTeam("t2");
    LMS.removeTeam("t3");
    cout<<endl;

    // Depart team

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.removeTeam("t1");
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.addTeam("t1", 11);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.transferPlayer("p1", "t1", "t2");
    cout<<endl;

    // Arrive team

    LMS.addTeam("t1", 11);
    LMS.addTeam("t2", 12);
    LMS.addPlayer("t1", "p1", 1, 1);
    LMS.removeTeam("t2");
    LMS.transferPlayer("p1", "t1", "t2");
    LMS.addTeam("t2", 12);
    LMS.transferPlayer("p1", "t1", "t2");

    return 0;
}
/*#include <iostream>
using namespace std;
#include "LeagueManagementSystem.h"
int main() {
    LeagueManagementSystem LMS;
    LMS.showAllTeams();
    cout << endl;
    LMS.addTeam( "Fenerbahce", 1907 );
    LMS.addTeam( "Tofas", 1957 );
    LMS.addTeam( "Anadolu Efes", 1951 );
    LMS.removeTeam( "Tofas" );
    LMS.addTeam( "Darussafaka", 1951 );
    LMS.addTeam( "Fenerbahce", 1907 );
    LMS.removeTeam( "Tofas" );
    cout << endl;
    LMS.addPlayer( "Fenerbahce", "Melih Mahmutoglu", 10, 2000000 );
    LMS.addPlayer( "Fenerbahce", "Sehmus Hazer", 2, 1000000 );
    LMS.addPlayer( "Darussafaka", "Ercan Osmani", 6, 1000000 );
    LMS.addPlayer( "Anadolu Efes", "Dogus Balbay", 4, 1000000 );
    LMS.addPlayer( "Anadolu Efes", "Bugrahan Tuncer", 10, 1500000 );
    LMS.removePlayer( "Darussafaka", "Ercan Osmani" );
    cout << endl;
    LMS.addPlayer( "Fenerbahce", "Stephen Curry", 10, 10000000 );
    LMS.addPlayer( "Karsiyaka", "Metecan Birsen", 1, 1000000 );
    LMS.addTeam( "Karsiyaka", 1912 );
    LMS.addPlayer( "Karsiyaka", "Metecan Birsen", 1, 1000000 );
    LMS.removePlayer( "Tofas", "Melih Mahmutoglu" );
    LMS.removePlayer( "Fenerbahce", "Bugrahan Tuncer" );
    LMS.transferPlayer( "Metecan Birsen", "Karsiyaka", "Fenerbahce" );
    LMS.transferPlayer( "Lebron James", "Los Angeles Lakers", "Fenerbahce" );
    LMS.transferPlayer( "Michael Jordan", "Darussafaka", "Fenerbahce" );
    LMS.transferPlayer( "Bugrahan Tuncer", "Anadolu Efes", "Fenerbahce" );
    cout << endl;
    LMS.showAllTeams();
    cout << endl;
    LMS.showTeam( "Fenerbahce" );
    cout << endl;
    LMS.showTeam( "Boston Celtics" );
    cout << endl;
    LMS.showPlayer( "Melih Mahmutoglu" );
    cout << endl;
    LMS.showPlayer( "Furkan Korkmaz" );
    return 0;
}*/
/**#include <iostream>
using namespace std;
#include "LeagueManagementSystem.h"
int main() {
    LeagueManagementSystem LMS;

    LMS.addTeam( "t1", 11 );
    LMS.addTeam( "t2", 12 );
    LMS.showAllTeams();
    cout << endl;
    LMS.removeTeam( "t2" );
    LMS.addPlayer( "t1", "p1", 1, 1 );
    LMS.addPlayer( "t1", "p2", 2, 2 );
    LMS.showTeam("t1");
    cout << endl;
    LMS.removePlayer("t1", "p2");
    LMS.showTeam("t1");
    return 0;
}*/
/*#include <iostream>
using namespace std;
#include "LeagueManagementSystem.h"
int main() {
    LeagueManagementSystem LMS;
    LMS.showAllTeams();
    cout << endl;
    LMS.addTeam( "Fenerbahce", 1907 );
    LMS.addTeam( "Tofas", 1957 );
    LMS.addTeam( "Anadolu Efes", 1951 );
    LMS.removeTeam( "Tofas" );
    LMS.addTeam( "Darussafaka", 1951 );
    LMS.addTeam( "Fenerbahce", 1907 );
    LMS.removeTeam( "Tofas" );
    cout << endl;
    LMS.addPlayer( "Fenerbahce", "Melih Mahmutoglu", 10, 2000000 );
    LMS.addPlayer( "Fenerbahce", "Sehmus Hazer", 2, 1000000 );
    LMS.addPlayer( "Darussafaka", "Ercan Osmani", 6, 1000000 );
    LMS.addPlayer( "Anadolu Efes", "Dogus Balbay", 4, 1000000 );
    LMS.addPlayer( "Anadolu Efes", "Bugrahan Tuncer", 10, 1500000 );
    LMS.removePlayer( "Darussafaka", "Ercan Osmani" );
    cout << endl;
    LMS.addPlayer( "Fenerbahce", "Stephen Curry", 10, 10000000 );
    LMS.addPlayer( "Karsiyaka", "Metecan Birsen", 1, 1000000 );
    LMS.addTeam( "Karsiyaka", 1912 );
    LMS.addPlayer( "Karsiyaka", "Metecan Birsen", 1, 1000000 );
    LMS.removePlayer( "Tofas", "Melih Mahmutoglu" );
    LMS.removePlayer( "Fenerbahce", "Bugrahan Tuncer" );
    LMS.transferPlayer( "Metecan Birsen", "Karsiyaka", "Fenerbahce" );
    LMS.transferPlayer( "Lebron James", "Los Angeles Lakers", "Fenerbahce" );
    LMS.transferPlayer( "Michael Jordan", "Darussafaka", "Fenerbahce" );
    LMS.transferPlayer( "Bugrahan Tuncer", "Anadolu Efes", "Fenerbahce" );
    cout << endl;
    LMS.showAllTeams();
    cout << endl;
    LMS.showTeam( "Fenerbahce" );
    cout << endl;
    LMS.showTeam( "Boston Celtics" );
    cout << endl;
    LMS.showPlayer( "Melih Mahmutoglu" );
    cout << endl;
    LMS.showPlayer( "Furkan Korkmaz" );
    return 0;
}*/
