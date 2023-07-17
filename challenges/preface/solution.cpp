/*
ID: oliverm4
TASK: preface
LANG: C++                 
*/
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;
#define MAX_DIGITS 4
#define MAX_NUMERALS 7


void get_numerals(int number, int numerals[7]){
  for(int i = 0;i<MAX_DIGITS;i++){
    int digit = number % 10;
    number /= 10;
    if(digit >= 5 && digit != 9){
      numerals[i*2+1]++;
      digit -= 5;
    }
    if(digit == 9){
        numerals[i*2+2]++;
        numerals[i*2]++;
        continue;
      }
    if(digit == 4){
      numerals[i*2+1]++;
      numerals[i*2]++;
      continue;
    }
    numerals[i*2]+=digit;
  }
}



int main()
{
  ofstream fout ("preface.out");
  ifstream fin ("preface.in");

  int n, numerals[MAX_NUMERALS]={0},maxs[MAX_NUMERALS]={0};
  char num_chars[MAX_NUMERALS] = {'I','V','X','L','C','D','M'};
  fin >> n;

  for(int i = 0;i<MAX_DIGITS;i++){

    int digit = n % 10;
    int power = pow(10,i);
    int segment = digit * power;
    n /= 10;
    cout << "maxes ";
    for(int j = 0;j<MAX_NUMERALS;j++){
      cout << maxs[j] << ' ';
    }
    cout << "\n";
    for(int j = 0;j<MAX_NUMERALS;j++){
      numerals[j] += maxs[j] * digit;
      maxs[j] *= 10;
    }

    for(int j = power;j<power*10;j+= power){
      int new_nums[MAX_NUMERALS] = {0};
      if(i != 3 || j <= segment){
        get_numerals(j,new_nums);
      }
      for(int k = 0;k<MAX_NUMERALS;k++){
        if(j<segment){
          numerals[k] += new_nums[k] * power;
        }
        if(j == segment){
          numerals[k] += new_nums[k];
        }
        maxs[k] += new_nums[k] * power;
      }
    }
    /*
    cout << "nums ";
    for(int j = 0;j<MAX_NUMERALS;j++){
      cout << numerals[j] << ' ';
    }
    cout << "\n";
    //*/

  }
  for(int i = 0;i<MAX_NUMERALS;i++){
    if(numerals[i] > 0){
      fout << num_chars[i] << ' ' << numerals[i] << "\n";
    }
  }

  return 0;
}
