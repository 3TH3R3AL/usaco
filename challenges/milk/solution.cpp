/*
ID: oliverm4
TASK: milk
LANG: C++                 
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct farmer {
  int amount;
  int cost;
};
bool cmp_farmers(const farmer& a, const farmer& b){
  return a.cost < b.cost;
}

int main()
{
  ofstream fout ("milk.out");
  ifstream fin ("milk.in");
  int n,m;
  fin >> n >> m;
  vector<farmer> farmers;
  for (int i = 0; i<m; i++) {
    struct farmer tmp;
    fin >> tmp.cost >> tmp.amount;
    farmers.push_back(tmp);

  }
  if(farmers.size() == 0){
    fout << 0 << "\n";
    return 0;
  }
  sort(farmers.begin(),farmers.end(),cmp_farmers);
  int cost = 0;
  int i = 0;
  while(n > 0){
    n -= farmers[i].amount;
    cost += farmers[i].cost * farmers[i].amount;
    i++;
  }
  cost += farmers[i-1].cost * n;
  fout << cost << "\n";
  

  return 0;
}
