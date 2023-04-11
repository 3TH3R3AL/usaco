/*
ID: oliverm4
TASK: combo
LANG: C++                 
*/
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

bool check_overlap(int a, int b,int n){
  if(b <= a+2 && b >= a-2){
    return true;
  }
  if(a+2 > n){
    return check_overlap(a-n,b,n+100);
  }
  if(a-2 <= 0){
    return check_overlap(a+n, b, n+100);
  }
  return false;
}

int circularDistance(int a, int b,int n){
  int dif = abs(a-b);
  return min(dif,n-dif);
}

int main()
{
  ofstream fout ("combo.out");
  ifstream fin ("combo.in");
  int n, combo1[3], combo2[3];
  fin >> n >> combo1[0] >> combo1[1] >> combo1[2] >> combo2[0] >> combo2[1] >> combo2[2];
  if(n < 5){
    cout << "initiating stupidity";
    int possibilities = 0;
    for (int i = 1; i<=n;i++) {
      int combo = 0;
      if(!check_overlap(i,combo1[0],n))
        combo = 2;
      if(!check_overlap(i, combo2[0], n)){
        if(combo == 2)
          continue;
        combo = 1;
      }
      //cout << "1\n";
      for (int j = 1; j<=n;j++) {
      
        if(!check_overlap(j,combo1[1],n)){
          if(combo == 1)
            continue;
          combo = 2;
        }
        if(!check_overlap(j, combo2[1], n)){
          if(combo == 2)
            continue;
          combo = 1;
        }
        //cout << "2\n";
        for (int k = 1; k<=n;k++) {
          
          if(!check_overlap(k,combo1[2],n)){
            if(combo == 1)
              continue;
          }
          if(!check_overlap(k, combo2[2], n)){
            if(combo == 2)
              continue;
          }
          //cout << "3\n";
          possibilities++;
        }
      }
    }
    fout << possibilities << "\n";
    return 0;
  }

  
  int num_overlap = 0;
  for(int i = 0;i<3;i++){

    if(check_overlap(combo1[i]+2, combo2[i],n)){
      num_overlap++;
    }else if(check_overlap(combo1[i]-2, combo2[i], n)){
      num_overlap++;
    }
  }
  if(num_overlap != 3){
    fout << "250\n";
    return 0;
  }

  int overlap[3] = {5-circularDistance(combo1[0],combo2[0],n),5-circularDistance(combo1[1],combo2[1],n),5-circularDistance(combo1[2],combo2[2],n)};
  
  fout << (250-overlap[0]*overlap[1]*overlap[2]) << "\n"; 
  return 0;
}
