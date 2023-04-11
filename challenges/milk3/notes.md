# USACO - Task "milk3"

## Challenge

## Solution
1. Load input into CAPS
2. set up processed vector, toCheck vector
3. add initial to toCheck
4. set up a while(toCheck size > 0) loop
5. pop the back of toCheck, test all possible pourings (nested loop)
6. search processed+to_check for pairings, add those not in to to_check
7. add thing to processed
7. end loop
9. go through processed to get all unique levels
10. print to fout and win
