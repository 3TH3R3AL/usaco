/*
ID: oliverm4
TASK: ariprog
LANG: C++                 
*/
#include <fstream>
#include <iostream>
#define MAX_SEQUENCES 10000
using namespace std;
struct ariprog {
  int start;
  int diff;
};
int main()
{
  ofstream fout ("ariprog.out");
  ifstream fin ("ariprog.in");
  int n,m;
  fin >> n >> m;
  int max_bi = (2*m*m);
  cout << "max_b: " << max_bi << "\n";
  bool bisquares[max_bi] = {0};
  for(int i = 0; i<=m; i++){
    for (int j = 0; j<=m; j++) {
      bisquares[i*i+j*j] = true;
    }
  }
  int ari_index = 0;
  int max_distance = max_bi/(n-1)+1; // Might fail b/c of roundoff
  cout << "max_d: " << max_distance << "\n";
  //struct ariprog sequences[MAX_SEQUENCES];
  for(int dist = 1; dist < max_distance; dist++){
    for(int i = 0; i<max_bi;i++){
      if(i+dist*(n-1) > max_bi){
        break;
      }
      int j;
      for(j = 0;j<n;j++){
        if(!bisquares[i+dist*j]){
          break;
        }
      }
      if(j == n){
        fout << i << " " << dist << "\n";
        ari_index++;
      }
    }
  }
  if(ari_index == 0){
    fout << "NONE\n";
  }  
  return 0;
}
