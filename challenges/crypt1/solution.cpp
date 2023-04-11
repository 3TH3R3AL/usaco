/*
ID: oliverm4
TASK: crypt1
LANG: C++                 
*/
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool checkDigits(int digits[],int n, int num,int expected_len){
  vector<int> digits_to_check;
  while(num > 0){
    digits_to_check.push_back(num % 10);
    num /= 10;
  }
  if(digits_to_check.size() != expected_len){
    return false;
  }
  for(int &i : digits_to_check){
    bool in = false;
    for(int j = 0;j<n;j++){
      if(digits[j]==i){
        in = true;
      }
    }
    if(!in){
      return false;
    }
  } 
  return true;
}

int main()
{
  ofstream fout ("crypt1.out");
  ifstream fin ("crypt1.in");
  int n;
  fin >> n;
  int digits[n];
  for (int &i : digits) {
    fin >> i;
  }
  int solutions = 0;
  /*
  * i j k
  * * l m
  * -----
  *
  */
  for (int &i : digits) {
  for (int &j : digits) {
  for (int &k : digits) { 
  for (int &l : digits) {
  for (int &m : digits) {
            int num1 = i*100 + j*10 + k;
            int subP1 = num1 * m;
            if(!checkDigits(digits, n, subP1, 3))
              continue;
            int subP2 = num1 * l;
            if(!checkDigits(digits, n, subP2, 3))
              continue;
            int final = subP1 + subP2 * 10;
            if(!checkDigits(digits, n, final, 4))
              continue;
            solutions++;
  }}}}}
  fout << solutions << "\n";
  return 0;
}
