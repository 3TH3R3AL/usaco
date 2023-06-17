/*
ID: oliverm4
TASK: holstein
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <cstring>
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

int breadth_first_scan(int depth, int prev[MAX_FEED], int length, int nreqs[MAX_VITAMIN])
{
  vector<int> possible;
  for(int i = 0; i < G;i++){
    if(prev[i] == 0 && i >= length)
      possible.push_back(i);
  }
  int l = possible.size();
  for (int i = 0; i < l; i++)
  {
    int to_add = possible[i];

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
      memcpy(ANS,prev,MAX_FEED*sizeof(int));
      ANS[to_add] = 1;
      return 1;
    }

    int nprev[MAX_FEED];
    memcpy(nprev,prev,MAX_FEED*sizeof(int));
    nprev[to_add] = 1;
    if(breadth_first_scan(depth-1,nprev,length+1,nnreqs)){
      return 1;
    }

  }
  return 0;
}

int main()
{
  cout << "start\n";
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
  cout << "1\n";
  int depth = 1;
  int st[MAX_FEED] = {0};
  /*
  while (!breadth_first_scan(depth, st, 0, REQS))
  {
    //cout << depth << " - depth\n";
    depth++;
  }
  cout << "2\n";

  fout << depth;
  for (int i = 0; i < MAX_VITAMIN; i++)
  {
    if(ANS[i] == 1){
      fout << " " << i+1;

    }
  }*/
  fout << "\n";

  return 0;
}
