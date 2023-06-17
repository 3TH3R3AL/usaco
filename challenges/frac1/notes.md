# USACO - Task "frac1"

- Super cool Euclidean algorithm, uses fast GCF to check common factors. 

```C++
bool rprime(int a, int b){
   int r = a % b;
   while(r != 0){
       a = b;
       b = r;
       r = a % b;
   }
   return(b == 1);
}
```

- also cool fraction comparison, via some rearangement:

```C++
int fraccompare (struct fraction *p, struct fraction *q) {
   return p->numerator * q->denominator - p->denominator *q->numerator;
}
```


## Challenge

## Solution

