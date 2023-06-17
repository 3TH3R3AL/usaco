/*
ID: oliverm4
TASK: sprime
LANG: C++                 
*/
#include <ctime>
#include <fstream>
#include <iostream>
#include <bitset>
#include <iterator>
#include <vector>
#include <cmath>
#define MAX_FACTOR 10000
using namespace std;
int P_DIGS[4] = {1,3,7,9};
vector<int> PRIMES;

bool is_prime(int to_check){
  bool prime = true;
  int max_factor = sqrt(to_check);
  for(int &i : PRIMES){
    if(i > max_factor)
      break;
    if(to_check % i == 0){
      prime = false;
      break;
    }
  }
  return prime;
}
vector<int> to_digits(int in){
  vector<int> digits;
  while(in > 0){

    int d = in % 10;
    in /= 10;
    digits.insert(digits.begin(),d);
  }
  return digits;
}

vector<int> next_sprimes(vector<int> original){
  vector<int> next;
  for(int &prefix : original){
    prefix *= 10;
    for(int &i : P_DIGS){
      int check = prefix + i;
      if(is_prime(check)){
        next.push_back(check);
      }
    }  
  }
  return next;
}
int main()
{
  ofstream fout ("sprime.out");
  ifstream fin ("sprime.in");
  bitset<MAX_FACTOR> numbers;
  int n;
  fin >> n;
  for(int i = 2; i < 100; i++){
    if(numbers.test(i)){
      continue;
    }
    // cout << "p " <<  i << '\n';
    for(int j = i+i;j<MAX_FACTOR;j+=i){
      numbers.set(j);
    }
  }
  for(int i = 2; i < MAX_FACTOR;i++){
    if(numbers.test(i))
      continue;
    PRIMES.push_back(i);
  }
  vector<int> sprimes;
  for(int i = 0;;i++){
    if(PRIMES[i] > 9)
      break;
    sprimes.push_back(PRIMES[i]);
  }
  while(to_digits(sprimes[0]).size() < n){
    sprimes = next_sprimes(sprimes);
  }
  for(int &i : sprimes)
    fout << i << "\n";
  return 0;
}




