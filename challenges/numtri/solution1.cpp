/*
ID: oliverm4
TASK: numtri
LANG: C++                 
*/
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

int N;
int LEN;
int* TRI;
int MAX = 0;

int get_index(int index, int depth){
  return (depth * (depth+1)/2)+index;
}

void search(int index, int depth, int sum){
  sum += TRI[get_index(index, depth)];
  depth++;
  if(depth == N){
    if(sum > MAX)
      MAX = sum; 
    return;
  }
  search(index,depth,sum);
  search(index+1, depth, sum);
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
  search(0, 0, 0);
  fout << MAX << "\n";
  free(TRI);
  return 0;
}
