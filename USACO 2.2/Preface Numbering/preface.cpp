/*
ID: ayushn.2
TASK: preface
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Function to convert decimal to Roman Numerals
vector<string> printRoman(int number)
{
  vector<string> toReturn;
  int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
  string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
  int i = 12;
  while (number > 0)
  {
    int div = number / num[i];
    number = number % num[i];
    while (div--)
    {
      cout << sym[i];
      /* Returning the correct value*/
      if (i == 0)
      {
        toReturn.push_back("I");
      }
      if (i == 1)
      {
        toReturn.push_back("I");
        toReturn.push_back("V");
      }
      if (i == 2)
      {
        toReturn.push_back("V");
      }
      if (i == 3)
      {
        toReturn.push_back("I");
        toReturn.push_back("X");
      }
      if (i == 4)
      {
        toReturn.push_back("X");
      }
      if (i == 5)
      {
        toReturn.push_back("X");
        toReturn.push_back("L");
      }
      if (i == 6)
      {
        toReturn.push_back("L");
      }
      if (i == 7)
      {
        toReturn.push_back("X");
        toReturn.push_back("C");
      }
      if (i == 8)
      {
        toReturn.push_back("C");
      }
      if (i == 9)
      {
        toReturn.push_back("C");
        toReturn.push_back("D");
      }
      if (i == 10)
      {
        toReturn.push_back("D");
      }
      if (i == 11)
      {
        toReturn.push_back("C");
        toReturn.push_back("M");
      }
      if (i == 12)
      {
        toReturn.push_back("M");
      }
    }
    i--;
  }
  return toReturn;
}

int main()
{
  ofstream fout("preface.out");
  ifstream fin("preface.in");
  int N;
  fin >> N;
  vector<string> numbers;
  for (int i = 0; i <= N; i++)
  {
    vector<string> toAdd = printRoman(i);
    numbers.insert(numbers.end(), toAdd.begin(), toAdd.end());
  }
  int cntI = 0;
  int cntV = 0;
  int cntX = 0;
  int cntL = 0;
  int cntC = 0;
  int cntD = 0;
  int cntM = 0;

  for (int i = 0; i < numbers.size(); i++)
  {
    if (numbers[i] == "I")
      cntI++;
    if (numbers[i] == "V")
      cntV++;
    if (numbers[i] == "X")
      cntX++;
    if (numbers[i] == "L")
      cntL++;
    if (numbers[i] == "C")
      cntC++;
    if (numbers[i] == "D")
      cntD++;
    if (numbers[i] == "M")
      cntM++;
  }
  if (cntI > 0)
    fout << "I " << cntI << endl;
  if (cntV > 0)
    fout << "V " << cntV << endl;
  if (cntX > 0)
    fout << "X " << cntX << endl;
  if (cntL > 0)
    fout << "L " << cntL << endl;
  if (cntC > 0)
    fout << "C " << cntC << endl;
  if (cntD > 0)
    fout << "D " << cntD << endl;
  if (cntM > 0)
    fout << "M " << cntM << endl;
  return 0;
}