/*
ID: oliverm4
TASK: numtri
LANG: C++                 
*/
#include <cstdlib>
#include <fstream>
#include <iostream>
#define TRI_INDEX(index,depth) (((depth-1) * depth/2)+index)
using namespace std;

int N;
int LEN;
int* TRI;
int MAX = 0;
//Depth is 1-indexed

void reduce(int depth){
  if(depth == 0){
    return;
  }
  for(int i = 0;i<depth;i++){  
    TRI[TRI_INDEX(i, depth)] += max(TRI[TRI_INDEX(i, (depth+1))],TRI[TRI_INDEX(i+1, (depth+1))]);
  }
  reduce(depth-1);
}
int main()
{
  ofstream fout ("numtri.out");
  ifstream fin ("numtri.in");
  fin >> N;
  LEN = N * (N+1)/2;
  TRI = (int *) malloc(sizeof(int)*LEN);
  for(int i = 0;i<LEN;i++){
    fin >> TRI[i];
  }
  reduce(N-1);
  fout << TRI[0] << "\n";
  free(TRI);
  return 0;
}
