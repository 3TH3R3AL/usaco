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
void printVector(vector<wormhole> vec) {
    cout << "[ ";
    for (int i = 0; i < vec.size(); i++) {
        cout << " { "<< vec[i].x << " " << vec[i].y << " }, ";
    }
    cout << "]" << endl;
}

void printPairings(vector<pairing> vec) {

    cout << "[ ";
    for (int i = 0; i < vec.size(); i++) {
        cout << " { "<< vec[i].p[0].x << " " << vec[i].p[0].y << " -> " << vec[i].p[1].x << " " << vec[i].p[1].y << " } ";
    }
    cout << "]" << endl;
}
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
        bool no_collide = true;
        for(int k = 0;k<pairings.size();k++){
          for(int l = 0;l<2;l++){
            if(k == i && l == j){
              continue;
            }
            if(pairings[k].p[l].y != pairings[i].p[j].y){
              continue;
            }

            if(pairings[k].p[l].x < pairings[i].p[j].x && pairings[k].p[l].x > testing.x){
              no_collide = false;
            }
          }
        }
        if(!no_collide){
          continue;
        }
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
        bool no_collide = true;
        for(int k = 0;k<pairings.size();k++){
          for(int l = 0;l<2;l++){
            if(k == i && l == j){
              continue;
            }
            if(pairings[k].p[l].y != pairings[i].p[j].y){
              continue;
            }

            if(pairings[k].p[l].x < pairings[i].p[j].x && pairings[k].p[l].x > testing.x){
              no_collide = false;
            }
          }
        }
        if(!no_collide){
          continue;
        }

        if(check_wormhole_sub(i, !j, orig, pairings))
          return 1;
      }
    }
  }
  return 0;
}
int check_pairings(vector<pairing> pairings){
  //cout << "check_pairings: ";
  printPairings(pairings);
  for(int i = 0;i<pairings.size();i++){
    for(int j = 0;j<2;j++){
        if(check_wormhole(i, j, pairings[i].p[j], pairings))
          return 1;
    }
  }
  return 0;
}

int check_wormholes(vector<wormhole> wormholes,vector<pairing> pairings){
  //printVector(wormholes);
  //printPairings(pairings);
  struct pairing tmp;
  int total = 0;
  tmp.p[0] = wormholes[0];
  wormholes.erase(wormholes.begin());
  pairings.push_back(tmp);
  if(wormholes.size() == 1){ 
    pairings.back().p[1] = wormholes[1];
    return check_pairings(pairings);
  }
  for(int i = 0;i<wormholes.size();i++){
    //cout << "loop start ";
    //printVector(wormholes);
    //cout << "putting " << wormholes[i].x << " " << wormholes[i].y << "\n";
    pairings.back().p[1] = wormholes[i];
    wormholes.erase(wormholes.begin()+i);
    total += check_wormholes(wormholes, pairings);
    wormholes.insert(wormholes.begin()+i,pairings.back().p[1]);
    //cout << "loop end ";
    //printVector(wormholes);
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
  //printVector(wormholes);
  int total = check_wormholes(wormholes,null_pairings);
  cout << total << "\n";
  fout << total << "\n";


  return 0;
}
