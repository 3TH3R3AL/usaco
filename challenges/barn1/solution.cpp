/*
ID: oliverm4
TASK: barn1
LANG: C++                 
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  ofstream fout ("barn1.out");
  ifstream fin ("barn1.in");
  unsigned int m, s, c;
  fin >> m >> s >> c;
  int *stalls = new int[s+2]();
  for (int i = 0; i < c; i++) {
    int tmp;
    fin >> tmp;
    stalls[tmp] = 1;
  }
  vector<int> sections;
  bool going;
  int low = -1;
  int high = 0;
  int current = 0;
  for (int i = 0; i<s+1; i++) {
    if(stalls[i] == 1){
      high = i;
      if(going){
        continue;
      }
      if(low == -1){
        low = i;
      }
      sections.push_back(current);
      current = 0;
      going = true;
      continue;
    }
    current++;
    going = false;
  }
  sections.erase(sections.begin()); 
  cout << "sections ";
  for (int i = 0; i < sections.size(); i++) {
    cout << sections[i] << " ";
  }
  
  cout << "\n";
  sort(sections.begin(),sections.end(),greater<int>());
  int range = high - low + 1;
  cout << "range " << range << "\n";
  
  for (int i = 0; i<(m-1) && i < sections.size(); i++) {
    range -= sections[i];
    cout << "subbed " << sections[i] << "\n";
  }

  fout << range << "\n";
  
  delete[] stalls; 
  return 0;
}
