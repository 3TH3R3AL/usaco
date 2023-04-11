/*
ID: oliverm4
TASK: milk3
LANG: C++                 
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#define NUM_BUCKETS 3
using namespace std;

int CAPS[NUM_BUCKETS];
int main()
{
  ofstream fout ("milk3.out");
  ifstream fin ("milk3.in");
  fin >> CAPS[0] >> CAPS[1] >> CAPS[2];
  vector<array<int,NUM_BUCKETS>> processed, to_check;
  to_check.push_back({0,0,CAPS[2]});
  //cout << "1\n";
  while(to_check.size() > 0){
    //cout << "size " << to_check.size() << "\n";
    // This always checks to_check[0]
    for(int i = 0;i<3;i++){
      //cout << "to_check[" << i << "] = " << to_check[0][i] << "\n";
      if(to_check[0][i] == 0) continue;
      //cout << "2\n";
      for(int j = 0;j<3;j++){
        if(i == j || to_check[0][j] == CAPS[j]) 
          continue;
        int to_pour = min(to_check[0][i], CAPS[j]-to_check[0][j]);
        array<int,NUM_BUCKETS> to_add;
        to_add[i] = to_check[0][i] - to_pour;
        to_add[j] = to_check[0][j] + to_pour;
        to_add[(~(i+j)) & 3] = to_check[0][(~(i+j)) & 3]; // Bitwise hack
        int k;
        for(k = 0;k<processed.size();k++){
          bool same = true;
          for(int l = 0;l<3;l++){
            if(processed[k][l] != to_add[l])
              same = false;
          }
          if(same)
            break;
        }
        int h;

        for(h = 0;h<to_check.size();h++){
          bool same = true;
          for(int l = 0;l<3;l++){
            if(to_check[h][l] != to_add[l])
              same = false;
          }
          if(same)
            break;
        }
        if(h == to_check.size() && k == processed.size()){
          to_check.push_back(to_add);
        }
      }
    }
  processed.push_back(to_check[0]);
  to_check.erase(to_check.begin());
    

  }
  vector<int> levels;
  for(int i = 0;i<processed.size();i++){
    bool is_in = false; 
    for(int &j : levels){
      if(j == processed[i][2])
        is_in = true;
    }
    if(!is_in && processed[i][0] == 0)
      levels.push_back(processed[i][2]);
  }
  sort(levels.begin(),levels.end());
  for(int i = 0;i<levels.size()-1;i++){
    fout << levels[i] << " ";
  }

  fout << levels.back() << "\n";
  return 0;
}
