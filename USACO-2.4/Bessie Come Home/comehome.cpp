/*
ID: ayushn.2
TASK: XXXXXXXXX
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/*

What this program will do, is first of all create a struct, to store all the child nodes, instead of storing all the parent nodes, to create a nodegraph.

*/
struct node {
    char id;
    int distance;
};


struct nodeGraph {
    char id;
    int distance;
    vector<node> childNodes;
};


int dfs(vector<nodeGraph> maze) {
    vector<char> solved; // Holds the char ID for solved.
    vector<int> unsolved; // The vector location. 
    int shortestLength = 1215752191;
    int currentLength = 0;

    //Finding Z
    for(int i = 0; i < maze.size(); i++) {
        if(maze[i].id == 'Z') {
            unsolved.push_back(i);
            break;
        }
    }


    while(unsolved.size() > 0) {
        // First add the node
        nodeGraph currentNode = maze[unsolved[unsolved.size()]];

        // Next search for the lengths
        bool nodeFound = false;
        for(int j = 0; j < currentNode.childNodes.size(); j++) {
            // New node checked
            bool isFound = false;
            for(int k = 0; k < solved.size(); k++) { // Checking if already solved
                if(solved[k] == currentNode.childNodes[j].id) // Found
                    isFound = true;
            }
            if(isFound)
                continue;

            if(isFound == false) {
                nodeFound = true;
                // Found a new node
                currentLength += currentNode.childNodes[j].distance; // Update currentLength
                bool childNodes = false;
                for(int i = 0; i < maze.size(); i++) { // Checking for the ID and adding it to unsolved
                    if(maze[i].id == currentNode.childNodes[j].id) {
                        unsolved.push_back(i);
                        childNodes = true;
                        break;
                    }
                }
                if(childNodes == false) {
                    if(shortestLength > currentLength) {
                        shortestLength = currentLength;
                    }
                    currentLength -= currentNode.childNodes[j].distance;
                }
                break;
            }
        }
        if(nodeFound == false) {
            solved.push_back(currentNode.id);
            currentLength -= currentNode.distance;
            unsolved.pop_back();
        }
    }
    return shortestLength;

}

int main()
{
    ofstream fout ("comehome.out");
    ifstream fin ("comehome.in");
    int N;
    fin >> N;
    vector<nodeGraph> maze;
    for(int i = 0; i < N; i++) {
        char a, b;
        int x;
        fin >> a >> b;
        fin >> x;
        node z;
        z.id = a;
        z.distance = x;
        bool found = false;
        for(int j = 0; j < maze.size(); j++) {
            if(maze[j].id == b) {
                found = true;
                maze[j].childNodes.push_back(z);
            }
        }
        if(found == false) {
            nodeGraph l;
            l.childNodes.push_back(z);
            l.id = b;
            maze.push_back(l);
        }
    }

    // Now we need to do BFS from Z



    fout << dfs(maze) << endl;
    return 0;
    
}