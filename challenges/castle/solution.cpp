/*
ID: oliverm4
TASK: castle
LANG: C++                 
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 
#define WEST(num) (num & 1)
#define NORTH(num) ((num >> 1) & 1)
#define EAST(num) ((num >> 2) & 1)
#define SOUTH(num) ((num >> 3) & 1)
#define ROOM(num) (num >> 4)
#define MAX_SIZE 50

int W,H, C, NODES[MAX_SIZE][MAX_SIZE];
vector<int> ROOMS;
int flood_fill(int x, int y){
  int ret = 1;
  int num = NODES[x][y];
  NODES[x][y] += C << 4;
  if(!WEST(num) && x != 0 && ROOM(NODES[x-1][y]) == 0){
    ret+=flood_fill(x-1,y);
  }
  if(!EAST(num) && x != W && ROOM(NODES[x+1][y]) == 0){
    ret+=flood_fill(x+1,y);
  }
  if(!NORTH(num) && y != 0 && ROOM(NODES[x][y-1]) == 0){
    ret+=flood_fill(x,y-1);
  }
  if(!SOUTH(num) && y != H && ROOM(NODES[x][y+1]) == 0){
    ret+=flood_fill(x,y+1);
  }
  return ret;
}

int main()
{
  ofstream fout ("castle.out");
  ifstream fin ("castle.in");
  fin >> W >> H;
  for(int i = 0;i<H;i++){
    for(int j = 0;j<W;j++){
      fin >> NODES[j][i];
    }
  }
  
  ROOMS.push_back(0);
  for(int i = 0;i<H;i++){
    for(int j = 0;j<W;j++){
      
      if(ROOM(NODES[j][i]) == 0){
        C++;
        ROOMS.push_back(flood_fill(j, i));
      }
    cout << ROOM(NODES[j][i]) << " ";
    }
    cout << "\n";
  }

  
  fout << C << "\n";
  //cout << C << "\n";
  int M = *max_element(ROOMS.begin(),ROOMS.end());
  fout << M <<"\n"; 
  //cout << M << "\n";
  int max_x = 0;
  int max_y = 0;
  int east = 0;
  int max_possible = 0;
  for(int j = 0;j<W;j++){
    for(int i = H-1;i>=0;i--){
      int node = NODES[j][i];
      if(NORTH(node) && i != 0 && ROOM(node) != ROOM(NODES[j][i-1]) && ROOMS[ROOM(node)] + ROOMS[ROOM(NODES[j][i-1])] > max_possible){
        max_possible = ROOMS[ROOM(node)] + ROOMS[ROOM(NODES[j][i-1])];
        max_x = j;
        max_y = i;
        east = 0;
      }
      if(EAST(node) && j != W-1 && ROOM(node) != ROOM(NODES[j+1][i]) && ROOMS[ROOM(node)] + ROOMS[ROOM(NODES[j+1][i])] > max_possible){
        max_possible = ROOMS[ROOM(node)] + ROOMS[ROOM(NODES[j+1][i])];
        max_x = j;
        max_y = i;
        east = 1;
      }
    } 
  }
  fout << max_possible << "\n";
  if(east){
    fout << max_y+1 << ' ' << max_x+1 << " E\n";
  }else {
    fout << max_y+1 << ' ' << max_x+1 << " N\n";
  }

  return 0;
}
