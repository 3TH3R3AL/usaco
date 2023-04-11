/*
ID: oliverm4
TASK: wormhole
LANG: C++                 
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int N;

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
struct wormhole {
  int w[2];
};
bool check_wormholes(struct wormhole wormholes[], struct wormhole pairings[]){
  int num_w = sizeof(wormholes)/sizeof(struct wormhole);
  int num_p = sizeof(pairings)/sizeof(struct wormhole);
  
}
  
int main()
{
  ofstream fout ("wormhole.out");
  ifstream fin ("wormhole.in");
  fin >> N;
  wormhole wormholes[N];
  for(int i = 0;i<N;i++){
    fin >> wormholes[i].w[0];
    fin >> wormholes[i].w[1];
  }
  int pairings = int[factorial(N-1)][N/2][2][2];

  return 0;
}
