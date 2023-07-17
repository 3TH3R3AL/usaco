/*
ID: oliverm4
TASK: hamming
LANG: C++                 
*/
#include <fstream>
#include <iostream>
#include <cmath>
#define MAX_WORDS 64

using namespace std;

int N, B, D, FOUND, MAX_CODE, SOLUTION[MAX_WORDS];

int calculate_hamming_distance(int a, int b){
  int d = 0;
  int diff = a ^ b;
  for (int i = 1; i <= MAX_CODE; i *= 2) {
    if(diff & i)
      d++;
  }
  return d;
}


int main()
{
  ofstream fout ("hamming.out");
  ifstream fin ("hamming.in");
  fin >> N >> B >> D;
  MAX_CODE = (int)pow(2,B);
  for(int i = 0;FOUND < N;i++){
    SOLUTION[0] = i;
    FOUND = 1;
    for(int j = 0;j <= MAX_CODE;j++){
      bool c = true;
      for (int k = 0; k < FOUND; k++) {
        if(calculate_hamming_distance(j, SOLUTION[k]) < D){
          c = false;
          break;
        }
      }
      if(c){
          SOLUTION[FOUND] = j;
          FOUND++;
          if(FOUND >= N)
            break;
      }
    }
  }
  if(FOUND != N){
    cerr << "ERROR: No Solution Found";
  }else{
    for (int i = 0; i < N; i++) {
      if(i % 10 == 0){
        fout << SOLUTION[i];
      }else {
        fout << " " <<  SOLUTION[i];
      }
      if(i % 10 == 9){
        fout << "\n";
      }
    }
    if(N % 10 != 0)
      fout << "\n";
  }

  return 0;
}
