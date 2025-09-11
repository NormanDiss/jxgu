/*
ID: ayushn.2
TASK: money
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct vectorPair {
    vector<int> nums;
    int sum;
};

int dfs(vector<int> numbers, int N)
{ 
    /*
    0. Three Vectors, 1: unsolved 2: encountered 3: solutions
    1. Initialize with all the starting numbers
    2. Check though numbers, if the sum is valid.
        If the sum is N, then add to the solutions vector, and then 
    3. If the sum valid then check if already in encountered (ordered vector)
    4. If old, continue in for loop. 
    5. If new, than add to encountered and then solve that new one.
    6. Once re encountered, if there are no new ones, then finish it off and pop
    */    
    vector<vectorPair> unsolved;
    vector<vectorPair> encountered;
    vector<vector<int> > solutions; // Not really used for DFS more for solutions counting.
    
    // Adding initial numbers
    for(int i = 0; i < numbers.size(); i++) {
        vectorPair x;
        x.sum = numbers[i];
        x.nums.push_back(numbers[i]);
        unsolved.push_back(x);
        encountered.push_back(x);
    }

    // DFS

    while(unsolved.size() > 0) {

        // Allocate current node
        vectorPair currentNode = unsolved[unsolved.size()];

        // See which node should be used
        bool foundPair = false;

        for(int i = 0; i < numbers.size(); i++) {
            // Check if valid
            if((currentNode.sum + numbers[i]) > N)
                continue;
            // Check if already encountered
            bool found = false;
            vector<int> toAdd = currentNode.nums;
            toAdd.push_back(numbers[i]);
            sort(toAdd.begin(), toAdd.end());
            for(int j = 0; j < encountered.size(); j++) {
                if(encountered[j].nums == toAdd)
                    found = true;
            }
            if(found) {
                continue;
            } else {
                currentNode.sum += numbers[i];
                currentNode.nums = toAdd;
                foundPair = true;
                break;
            }
        }

        // Now that a pair has been found
        if(foundPair) {
            unsolved.push_back(currentNode);
            cout << "US!" << endl;
        } else {
            encountered.push_back(currentNode);
            unsolved.pop_back();
            cout << "S!" << endl;
        }

        // Finally, check if 100
        if(currentNode.sum == 100) {
            solutions.push_back(currentNode.nums);
            cout << "SOLUTION!" << endl;
        }
    }





   return solutions.size();
} 

int main()
{
    ofstream fout ("money.out");
    ifstream fin ("money.in");
    int V, N;
    fin >> V >> N;
    vector<int> coins;
    coins.resize(V);
    /*
    The Idea:

    Use DFS to add numbers together
    */

    for(int i = 0; i < V; i++) {
        fin >> coins[i];
    }
    cout << dfs(coins, N) << endl;

    return 0;

}