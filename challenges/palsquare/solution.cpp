/*
ID: oliverm4
TASK: palsquare
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
  ofstream fout ("palsquare.out");
  ifstream fin ("palsquare.in");
  int b;
  fin >> b;
  for(int i = 1;i<=300;i++){
    string based = toBaseString(i*i,b);
    if(!isPalindrome(based)){
      continue;
    }
    fout << toBaseString(i,b) << " " << based << "\n";
  } 
  
  return 0;
}
