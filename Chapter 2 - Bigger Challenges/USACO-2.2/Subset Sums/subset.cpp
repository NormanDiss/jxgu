/*
ID: ayushn.2
TASK: subset
LANG: C++11
*/

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("subset.in");
    ofstream fout("subset.out");
    long long num=0, ways[800]={0};
    ways[0]=1;
    cin >> num;

    if(((num*(num+1))/2)%2 == 1)
    {
        fout << "0" << endl;
        return 0;
    }
    //THIS IS THE BLOCK OF CODE THAT IS SUPPOSED TO BE DERIVED FROM THE 
    //   O/1 KNAPSACK PROBLEM
    for (int i = 1; i <= num; i++) 
    {
        for (int j = (num*(num+1))/2 - i; j >= 0; --j) 
        {
            ways[j + i] += ways[j];
        }
    }
    fout << ways[(num*(num+1))/2/2]/2 << endl;
    return 0;
}