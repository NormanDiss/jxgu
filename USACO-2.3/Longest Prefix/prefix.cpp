/*
ID: ayushn.2
TASK: prefix
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool subStringValid(string prefixString, string toCheck) {
    if(prefixString.length() < toCheck.length()) {
        return false;
    }
    for(int i = 0; i < toCheck.length(); i++) {
        // cout << i << endl;
        if(prefixString.at(i) != toCheck.at(i))
            return false;
    }
    return true;
}

int dfs(vector<string> primitives, string nodes) {
    int longestString = 0;
    vector<string> solved;
    vector<string> unsolved;
    /* So what the code will do is store in solved an index of the current substrings created, and then there will be a method to "subtract" substrings from the main string, to figure out if it is a valid config. In addition, given a subtracted string, (part of the raw string) and the prefix to check, the program will return either TRUE or FALSE. TRUE will mean that the program will now continue to execute down that prefix string, farther and farther, false means it will execute the former string, if a string has already been solved, than there is no need to resolve it, so thats why solved exists, and once a substring is created, it will be iterated through solved to see if it already exists, and if it does will stop the DFS
    
    1. Check if prefix valid, starting with first iteration.
        - If not valid restart with different primitive
    2. If Valid, check if already in solved.
        - If already in solved, restart with different primitive
    3. If valid and new, then record size if greater than longest string than add, to Unsolved Vector
    4. Find Child nodes, and then do the same process.
    5. If Child nodes comes up empty (vector size doesn't change), pop this node and add it to solved.

    == Then by design, it will go to the previous parent node and check that for new children.
    */

   // Creating the first node(s). 

    for(int i = 0; i < primitives.size(); i++) {
        if(subStringValid(nodes, primitives[i])) {
            unsolved.push_back(primitives[i]);
        }
    }

   // Now DFS

    while(unsolved.size() > 0) {
            // Current Node
            string currentNode = unsolved.back();
            // cout << currentNode << endl;

            // Check if primitive valid
            bool didWork = false;
            
            for(int i = 0; i < primitives.size(); i++) {
                // Iterate through all the different nodes and check if they are valid.

                if(subStringValid(nodes, currentNode + primitives[i])) {
                    

                    // Now check if already solved
                    bool didfind = false;

                    for(int j = 0; j < solved.size(); j++) {
                        if(solved[j] == (currentNode + primitives[i])) {
                            didfind = true;
                            break;
                        }

                    }

                    if(didfind == false) {
                        didWork = true;
                        currentNode += primitives[i];
                        break;
                    }
                }
            }

            if(didWork) {
                // cout << "Longest String!" << " | " << currentNode << " ";
                // cout << currentNode.size() << endl;
                if(currentNode.size() > longestString) {
                    // cout << "Longer!" << endl;
                    longestString = currentNode.length();
                }
                unsolved.push_back(currentNode);
            } else {
                // Code to pop 

                // Fully solved, so add to solved
                solved.push_back(currentNode);
                unsolved.pop_back();

            }

    }




    return longestString;
}

int main()
{
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");
    vector<string> primitives;
    string rawString = "";
    while(true) {
        string x;
        fin >> x;
        if(x == ".")
            break;
        else
            primitives.push_back(x);
    } 
    while(fin) {
        string y;
        fin >> y;
        rawString += y;
    }

    fout << dfs(primitives, rawString) << endl;
    return 0;
    
}