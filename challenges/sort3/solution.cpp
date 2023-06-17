/*
ID: oliverm4
TASK: sort3
LANG: C++                 
*/
#include <fstream>
#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <cstring>
using namespace std;

int SWITCHES = 0;

void bsort(int arr[],int length){
  int counts[4] = {0,0,0,0};
  for (int i = 0; i < length; i++)
  {
    counts[arr[i]]++;
  }
  int j = 0;
  for (int i = 0; i < 4; i++)
  {
    for (int k = 0; k < counts[i];k++)
    {
      arr[j] = i;
      j++; 
    }
  }
  
  
}

int two_swap(int sorted[], int raw[], int length){
  for(int i = 0; i < length;i++){
    if(sorted[i] == 3)
      break;

    if(raw[i] == sorted[i])
      continue;

    for(int j = i+1; j < length;j++){
      if(raw[j] != sorted[i] || raw[i] != sorted[j])
        continue;
      int tmp = raw[j];
      raw[j] = raw[i];
      raw[i] = tmp;
      return 1;
    }
  }
  return 0;
}


int one_swap(int sorted[], int raw[], int length){
  for(int i = 0; i < length;i++){
    if(sorted[i] == 3)
      break;

    if(raw[i] == sorted[i])
      continue;

    for(int j = i+1; j < length;j++){
      if(raw[j] != sorted[i] || raw[j] == sorted[j])
        continue;
      int tmp = raw[j];
      raw[j] = raw[i];
      raw[i] = tmp;
      return 1;
    }
  }
  return 0;
}

int main()
{
  ofstream fout ("sort3.out");
  ifstream fin ("sort3.in");
  int n;
  fin >> n;
  int records[n];
  for (int i = 0; i < n; i++) {
    fin >> records[i];
  } 
  int switches = 0;
  int sorted[n];
  memcpy(sorted,records,sizeof(int) * n);
  bsort(sorted,n);
  while(two_swap(sorted,records,n)){
    switches++;
  }
  while(one_swap(sorted,records,n)){
    switches++;
    while(two_swap(sorted,records,n)){
      switches++;
    }
  }
  fout << switches << "\n";

  return 0;
}
