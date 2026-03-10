/*
ID: ayushn.2
TASK: holstein
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
struct feedType {
    int scoops;
    int totalFeed;
    bool satisfied;
};


vector<int> addTwoFeeds(vector<int> feed1, vector<int> feed2) {
    vector<int> total;
    total.resize(feed1.size());
    for(int i = 0; i < feed1.size(); i++) {
        total[i] = (feed1[i] + feed2[i]);
    }
    return total;
}

int feedTotal(vector<int> feed) {
    int total = 0;
    for(int i = 0; i < feed.size(); i++) {
        total += feed[i];
    }
    return total;
}
bool checkMerit(vector<int> toCheck, vector<int> checkAgainst) {
    for(int i = 0; i < toCheck.size(); i++) {
        if (toCheck[i] < checkAgainst[i]) {
            return false;
        }
        
    }
    return true;
}

feedType vecSum(string binaryString, vector<vector<int> > feed, vector<int> checkAgainst) {
    feedType toReturn;
    toReturn.scoops = 0;
    vector<int> currentVector(feed[0].size(), 0);
    for(int i = 0; i < feed.size(); i++) {
        int x = binaryString.at(i);
        x -= 48;
        if(x == 1) {
            toReturn.scoops += 1;
            vector<int> replace = addTwoFeeds(currentVector, feed[i]);
            currentVector = replace;
        }
    }
    toReturn.totalFeed = feedTotal(currentVector);
    toReturn.satisfied = checkMerit(currentVector, checkAgainst);
    return toReturn;
}


int main()
{
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
    int V, G;
    fin >> V;
    vector<int> vitAmount;
    vitAmount.resize(V);
    for(int i = 0; i < V; i++) {
        fin >> vitAmount[i];
    }
    fin >> G;
    vector<vector<int> > feed;
    for(int i = 0; i < G; i++) {
        vector<int> toInput;
        toInput.resize(V);
        for(int j = 0; j < V; j++) {
            fin >> toInput[j];
        }
        feed.push_back(toInput);
    }

    feedType topFeed;
    topFeed.scoops = 99999999;
    topFeed.totalFeed = 99999999;
    string currentA = "";
    // So now choose different types of feeds, and start adding them until not needed
    int n = pow(2, G) - 1;
    int currentMax = -100;
    vector<string> binaries;
    queue<string> q;
    q.push("1");
    while(n--)
    {
        string s1 = q.front();
        q.pop();
        string z = s1; // Random variable to store data with to append 0's to the end.
        while(z.length() < G) {
            z += "0";
        }
        binaries.push_back(z);
        // Do z, but with a 0 at the front instead of a 1
        z.replace(0, 1, "0");
        binaries.push_back(z);
        string s2 = s1;
        q.push(s1.append("0"));
        q.push(s2.append("1"));
    }
    
    for(int i  = 0; i < binaries.size(); i++) {
        feedType a = vecSum(binaries[i], feed, vitAmount);
        if (a.satisfied == true) {
            if (a.scoops < topFeed.scoops) {
                topFeed.scoops = a.scoops;
                topFeed.totalFeed = a.totalFeed;
                currentA = binaries[i];
            } 
            if (a.scoops == topFeed.scoops && a.totalFeed < topFeed.totalFeed) {
                topFeed.scoops = a.scoops;
                topFeed.totalFeed = a.totalFeed;
                currentA = binaries[i];
            }
        }
    }
    fout << topFeed.scoops;
    cout << topFeed.scoops;
    // Formatting the print of topscoop
    for(int i = 0; i < currentA.size(); i++) {
        int x = currentA.at(i);
        x -= 48;
        if(x == 1) {
            fout << " " << i + 1;
            cout << " " << i + 1;
        }
    }
    fout << endl;
    cout << endl;
    return 0;
    
}