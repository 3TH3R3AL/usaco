/*
ID: oliverm4
TASK: transform
LANG: C++                 
*/
#include <fstream>
#include <iostream>

using namespace std;
void printGrid(char grid[], int n){
  for (int i = 0; i < n; i++) {
    for(int j = 0;j<n;j++){
      cout << grid[i*n+j];
    }
    cout << "\n";
  }
}
void rotateGrid(char grid[], int n){
  int tmp[n*n];
  for(int i = 0;i<n;i++){
    for (int j = 0; j < n; j++) {
      tmp[(j)*n+(n-1-i)] = grid[i*n+j]; 
    }
  }
  for(int i = 0;i<n;i++){
    for (int j = 0; j < n; j++) {
      grid[i*n+j] = tmp[i*n+j]; 
    }
  }
}

void reflectGrid(char grid[], int n){
  int tmp[n*n];
  for(int i = 0;i<n;i++){
    for (int j = 0; j < n; j++) {
      tmp[(i)*n+(n-1-j)] = grid[i*n+j]; 
    }
  }
  for(int i = 0;i<n;i++){
    for (int j = 0; j < n; j++) {
      grid[i*n+j] = tmp[i*n+j]; 
    }
  }
}

int sameGrid(char grid1[], char grid2[], int n){
  
  for(int i = 0;i<n;i++){
    for (int j = 0; j < n; j++) {
      if(grid1[i*n+j] != grid2[i*n+j]){
        return 0;
      } 
    }
  }
  return 1;
}

int main()
{
  ofstream fout ("transform.out");
  ifstream fin ("transform.in");
  int n;
  fin >> n;
  char in[n*n];
  char out[n*n];
  for(int i = 0;i<n*n;i++){
    fin >> in[i]; 
    
  }
  for(int i = 0;i<n*n;i++){
    fin >> out[i]; 
  }
  rotateGrid(in,n);
  
  if(sameGrid(in, out,n)){
    fout << "1\n";
    return 0;
  }
   
  rotateGrid(in,n);
  
  if(sameGrid(in, out,n)){
    fout << "2\n";
    return 0;
  }
  
  rotateGrid(in,n);
  
  if(sameGrid(in, out,n)){
    fout << "3\n";
    return 0;
  }

  rotateGrid(in,n);
 
  if(sameGrid(in, out,n)){
    fout << "6\n";
    return 0;
  }
  reflectGrid(in, n);

  if(sameGrid(in, out,n)){
    fout << "4\n";
    return 0;
  } 

  rotateGrid(in,n);
  
  if(sameGrid(in, out,n)){
    fout << "5\n";
    return 0;
  }
   
  rotateGrid(in,n);
  
  if(sameGrid(in, out,n)){
    fout << "5\n";
    return 0;
  }
  
  rotateGrid(in,n);
  
  if(sameGrid(in, out,n)){
    fout << "5\n";
    return 0;
  }



  fout << "7\n";
  return 0;
}
