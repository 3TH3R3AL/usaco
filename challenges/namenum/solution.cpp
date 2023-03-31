/*
ID: oliverm4
TASK: namenum
LANG: C++                 
*/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#define MAX_WORDS 5000

int chrToNum(char in){
  int casted = (int) in;
  if(casted > 113){
    casted++;
  }
  return (casted-91)/3;
}


int main()
{
  ofstream fout ("namenum.out");
  ifstream fin ("namenum.in");
  ifstream dictIn ("dict.txt");
  long n;
  fin >> n;
  string nString = to_string(n);
  int len = nString.length();
  int numArr[len];
  for (int i = 0; i < len; i++) {
    numArr[i] = ((int) nString[i])-48; 
    cout << numArr[i];
  }
  
  char words[MAX_WORDS][len];
  int index = 0;
  char *word;
  while(cin >> word){
    
    for(int i = 0;i<len;i++){
      if(chrToNum(word[i]) != numArr[i]){
        break;
      }
      if(i == len-1){
        memcpy(words[index][0],word,len*sizeof(char));
      }
    }
  }
    

  return 0;
}
