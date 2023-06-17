/*
ID: oliverm4
TASK: sort3
LANG: C++                 
*/
#include <fstream>
#include <iostream>
using namespace std;
int BOUNDARIES[4];

int check_boundaries(int position){
  for (int i = 0; i < 4; i++) {
    if(position < BOUNDARIES[i])
      return i;
  }
  return 1;
}

int main()
{
  ofstream fout ("sort3.out");
  ifstream fin ("sort3.in");
  int n;
  fin >> n;
  int records[n];
  int nums[4];
  for (int i = 0; i < n; i++) {
    fin >> records[n];
    nums[records[n]]++;
  } 
  BOUNDARIES[0] = 0;
  BOUNDARIES[1] = nums[1];
  BOUNDARIES[2] = nums[1]+nums[2];
  BOUNDARIES[3] = n;
  int oswitches = 0;
  int switches = 0;
  do {
    oswitches = switches;
    for (int i = 0; i < n; i++) {
      int correct_medal = check_boundaries(i); 
      if(records[i] == correct_medal){
        for (int j = BOUNDARIES[records[i]-1]; j < BOUNDARIES[records[i]]; j++) {
          if(records[j] == correct_medal){
            int t = records[j];
            records[j] = records[i];
            records[i] = t;
            switches++;
          }
        }
      }
    }
  } while(switches != oswitches);
  cout << BOUNDARIES[1] << " " << BOUNDARIES[2] << "\n";
  for(int i = 0; i < n;i++){
    cout << records[i] << " ";
  }
  cout << "\n";
  fout << switches;
  return 0;
}
