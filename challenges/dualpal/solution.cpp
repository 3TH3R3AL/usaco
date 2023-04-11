/*
ID: oliverm4
TASK: dualpal
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string alphabet = "0123456789ABCDEFGHIJKLM";
string toBaseString(int n,int base){
  vector<int> indices;
  while(n != 0){
    indices.push_back(n%base);
    n /= base;
  }
  string ret;
  for(int i = indices.size()-1;i>=0;i--){
     ret += alphabet[indices[i]];
  }
  return ret;
}

bool isPalindrome (string input){
  int len = input.length();
  for(int i = 0;i < (len >> 1);i++){
    if(input[i] != input[len-i-1]){
      return 0;
    }
  }
  return 1;
}



int main()
{
  ofstream fout ("dualpal.out");
  ifstream fin ("dualpal.in");
  int n, s;
  fin >> n >> s;
  int n_found = 0; 
  while(n_found < n){
    s++;
    int tot=0;
    
    for(int i = 2;i<=10;i++){
      if(isPalindrome(toBaseString(s, i))){
        tot++; 
        if(tot > 1){
          n_found++;
          fout << s << "\n";
          break;
        }
      }
    }
  }
  
  return 0;
}
