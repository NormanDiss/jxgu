#include <iostream>

using namespace std;

struct team {
    int home;
    int away;
};

bool fight(team homeTeam, team awayTeam) {
    return homeTeam.home == awayTeam.away;
}


int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        
    }

    return 0; 
}