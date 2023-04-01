/*
ID: oliverm4
TASK: namenum
LANG: C++                 
*/
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX_WORDS 5000

int chrToNum(char in){
  int casted = (int) in;
  if(casted > 81){
    casted--;
  }
  return (casted-59)/3;
}

int main()
{
  ofstream fout ("namenum.out");
  ifstream fin ("namenum.in");
  ifstream dictIn ("dict.txt");
  long long n;
  fin >> n;
  cout << "n " << n << "\n";
  string nString = to_string(n);
  cout << "ToS: " << nString << "\n";
  int ans_len = nString.length();
  int numArr[ans_len];
  for (int i = 0; i < ans_len; i++) {
    numArr[i] = ((int) nString[i])-'0'; 
  }
  vector<string> words; 
  int index = 0;
  string word;
  cout << "Tlen " << ans_len << "\n";
  while(dictIn >> word){
    int len = word.length();
    
    if(len != ans_len){
      continue;
    }
    for(int i = 0;i<len;i++){
      
      if(chrToNum(word[i]) != numArr[i]){
        break;
      }
      if(i == len-1){
        words.push_back(word);
      }
    }
  }
  if(words.empty()){
    fout << "NONE" << "\n";
  }
  for(const string& str : words){
    fout << str << "\n";
    cout << str << "\n";
  } 

  return 0;
}
