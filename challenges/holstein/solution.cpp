/*
ID: oliverm4
TASK: holstein
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_FEED 15
#define MAX_VITAMIN 25
int V, G, FEEDS[MAX_FEED][MAX_VITAMIN], REQS[MAX_VITAMIN], ANS[MAX_FEED];

bool check_reqs(int reqs[MAX_VITAMIN])
{
  for (int i = 0; i < V; i++)
  {
    if (reqs[i] > 0)
    {
      return false;
    }
  }
  return true;
}

int breadth_first_scan(int depth, int prev[MAX_FEED], int length, int nreqs[MAX_VITAMIN],int is)
{
  /*
  vector<int> possible;
  for(int i = 0; i < G;i++){
    if(prev[i] == 0 && i >= length)
      possible.push_back(i);
  }
  int l = possible.size();
  cout << "[";
  for (int j = 0; j < MAX_FEED; j++)
  {
    if(prev[j] == 1){
      cout << j << ",";
    }
  }
  cout << "]\n";*/

  for (int i = is; i < G; i++)
  {
    if(prev[i] == 1){
      continue;
    }
    int to_add = i;

    int nnreqs[MAX_VITAMIN];
    for (int j = 0; j < V; j++)
    {
      nnreqs[j] = nreqs[j] - FEEDS[to_add][j];
    }
    //cout << depth << " : " << i << "\n";
    if (depth == 1)
    {
      if (!check_reqs(nnreqs))
        continue;
      copy(prev,prev+MAX_FEED,ANS);
      ANS[to_add] = 1;
      return 1;
    }
    int nprev[MAX_FEED];
    copy(prev,prev+MAX_FEED,nprev);
    nprev[to_add] = 1;
    
    
    if(breadth_first_scan(depth-1,nprev,length+1,nnreqs,i)){
      return 1;
    }

  }
  return 0;
}

int main()
{

  ofstream fout("holstein.out");
  ifstream fin("holstein.in");
  fin >> V;
  int requirements[V];
  for (int i = 0; i < V; i++)
  {
    fin >> REQS[i];
  }
  fin >> G;
  for (int i = 0; i < G; i++)
  {
    for (int j = 0; j < V; j++)
    {
      fin >> FEEDS[i][j];
    }
  }
  int depth = 1;
  int st[MAX_FEED] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  //breadth_first_scan(depth, st, 0, REQS,0);
  while (!breadth_first_scan(depth, st, 0, REQS,0))
  {
    if(depth > MAX_FEED){
      cerr << "ERROR: NO SOLUTION FOUND within 3\n";
      return 1;
    }
    depth++;
  }
  fout << depth;
  for (int i = 0; i < MAX_FEED; i++)
  {
    if(ANS[i] == 1){
      fout << " " << i+1;

    }
  }
  fout << "\n";

  return 0;
}
