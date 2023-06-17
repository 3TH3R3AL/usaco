/*
ID: oliverm4
TASK: frac1
LANG: C++                 
*/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
struct Fraction {
  int numerator;
  int denominator;
  double value;
};
vector<int> PRIMES;

void genPrimes(int max){
  for (int i = 2; i < max; i++)
  {
    bool divisible = false;
    for(int &j : PRIMES){
      if(i % j == 0){
        divisible = true;
        break;
      }
    }
    if(!divisible){
      PRIMES.push_back(i);
    }
  }
  
}

bool is_reducible(int num, int den){
  for(int &j : PRIMES){
    if(num % j == 0 && den % j == 0){
      return true;
    }
  }
  return false;
}

int main()
{
  
  ofstream fout ("frac1.out");
  ifstream fin ("frac1.in");
  int n;
  fin >> n;
  genPrimes(n);
  vector<struct Fraction> fractions;
  struct Fraction first = {.numerator = 0,.denominator = 1,.value = 0};
  fractions.push_back(first);
  struct Fraction second = {.numerator = 1,.denominator = 1,.value = 1};
  fractions.push_back(second);
  for(int den = 2; den <= n; den ++){
    int index = 0;
    for(int num = 1; num <= den; num++){
      if(is_reducible(num,den))
        continue;
      double val = double(num) / double(den);
      for(; index < fractions.size(); index++){
        
        double to_check = fractions[index].value;
        if(to_check < val){
          //printf("%i - %i/%i\n",index,num,den);
          continue;
        }else if(to_check > val){

          Fraction to_add = {.numerator = num, .denominator = den, .value = val};
          fractions.insert(fractions.begin()+index,to_add);
          /*printf("{");
          for (Fraction &i: fractions)
            printf("%i/%i,",i.numerator,i.denominator);
          printf("}\n");*/

          break;

        } else {
          break;
        }
      }
      
    }
    
  }
  for (Fraction &i: fractions)
    fout << i.numerator << "/" << i.denominator << "\n";
  return 0;
}
