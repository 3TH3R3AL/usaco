/*
ID: oliverm4
TASK: skidesign
LANG: C++                 
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_LEN 1000
struct hill {
  int position;
  int distance;
};
bool cmp_hills(hill a,hill b){
  return a.position < b.position;
}
int calculateCost(vector<hill> to_buy){
  int cost = 0;
  for(hill &item : to_buy){
    cost += (item.distance+1)*(item.distance+1) - item.distance*item.distance;
  }
  return cost;
}

int main()
{
  ofstream fout ("skidesign.out");
  ifstream fin ("skidesign.in");
  int n;
  fin >> n;
  int b_index = 1, e_index = n-2;
  struct hill hills[n];
  for(int i = 0;i<n;i++){
    struct hill tmp;
    fin >> tmp.position;
    tmp.distance = 0;
    hills[i] = tmp;
  }
  sort(hills,hills+n,cmp_hills);
  vector<hill> start, end;
  start.push_back(hills[0]);
  end.push_back(hills[n-1]);
  while(true){
    if(end[0].position-start[0].position <= 17){
      break;
    }
    while(hills[b_index].position == start[0].position){
      start.push_back(hills[b_index]);
      b_index++;
    }

    while(hills[e_index].position == end[0].position){
      end.push_back(hills[e_index]);
      e_index--;
    }
    if(calculateCost(start) >= calculateCost(end)){
      for(hill &item : end){
        item.distance++;
        item.position--;
      }
    }else {
      for(hill &item : start){
        item.distance++;
        item.position++;
      }
    }
    
  }
  int total_cost = 0;
  for(hill &item : start){
    total_cost += item.distance*item.distance;
  }

  for(hill &item : end){
    total_cost += item.distance*item.distance;
  }
  fout << total_cost << "\n";
  return 0;
}
