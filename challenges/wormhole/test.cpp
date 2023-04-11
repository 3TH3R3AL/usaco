/*
ID: oliverm4
TASK: wormhole
LANG: C++                 
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
int N;
struct wormhole {
  int x;
  int y;
};
struct pairing {
  struct wormhole p[2];
};

// n is index in pairings, n2 is index in pairing

int check_wormhole_sub (int n,int n2,wormhole orig, vector<pairing> pairings){
  
  wormhole testing = pairings[n].p[n2];
  if(testing.x == orig.x && testing.y == orig.y){
    return 1;
  }
  for(int i = 0;i<pairings.size();i++){
    for(int j = 0;j<2;j++){
      if(pairings[i].p[j].y != testing.y){
        continue;
      }
      if(pairings[i].p[j].x > testing.x){
        if(check_wormhole_sub(i, !j, orig, pairings))
          return 1;
      }
    }
  }
  return 0;
}
int check_wormhole (int n,int n2,wormhole orig, vector<pairing> pairings){
  
  wormhole testing = pairings[n].p[n2];
  for(int i = 0;i<pairings.size();i++){
    for(int j = 0;j<2;j++){
      if(pairings[i].p[j].y != testing.y){
        continue;
      }
      if(pairings[i].p[j].x > testing.x){
        if(check_wormhole_sub(i, !j, orig, pairings))
          return 1;
      }
    }
  }
  return 0;
}
int check_pairings(vector<pairing> pairings){

  for(int i = 0;i<pairings.size();i++){
    for(int j = 0;j<2;j++){
        if(check_wormhole(i, j, pairings[i].p[j], pairings))
          return 1;
    }
  }
  return 0;
}
int check_wormholes(vector<wormhole> wormholes,vector<pairing> pairings){
  struct pairing tmp;
  int total = 0;
  tmp.p[0] = wormholes[0];
  wormholes.erase(wormholes.begin());
  pairings.push_back(tmp);
  if(wormholes.size() == 2){ 
    pairings.back().p[1] = wormholes[1];
    return check_pairings(pairings);
  }
  for(int i = 1;i<wormholes.size();i++){
    wormholes.erase(wormholes.begin()+i);
    pairings.back().p[1] = wormholes[i];
    total += check_wormholes(wormholes, pairings);
    wormholes.insert(wormholes.begin()+i,pairings.back().p[1]);
  }
  return total;
}

int main()
{
  ofstream fout ("wormhole.out");
  ifstream fin ("wormhole.in");
  fin >> N;
  vector<wormhole> wormholes;
  for(int i = 0;i<N;i++){
    wormhole tmp;
    fin >> tmp.x;
    fin >> tmp.y;
    wormholes.push_back(tmp);
  }
  vector<pairing> null_pairings;
  int total = check_wormholes(wormholes,null_pairings);
  cout << total << "\n";
  fout << total << "\n";


  return 0;
}
