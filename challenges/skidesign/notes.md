# USACO - Task "skidesign"

## Challenge
### Ski Course Design

Farmer John has N hills on his farm (1 <= N <= 1,000), each with an integer elevation in the range 0 .. 100. In the winter, since there is abundant snow on these hills, FJ routinely operates a ski training camp.

Unfortunately, FJ has just found out about a new tax that will be assessed next year on farms used as ski training camps. Upon careful reading of the law, however, he discovers that the official definition of a ski camp requires the difference between the highest and lowest hill on his property to be strictly larger than 17. Therefore, if he shortens his tallest hills and adds mass to increase the height of his shorter hills, FJ can avoid paying the tax as long as the new difference between the highest and lowest hill is at most 17.

If it costs x^2 units of money to change the height of a hill by x units, what is the minimum amount of money FJ will need to pay? FJ can change the height of a hill only once, so the total cost for each hill is the square of the difference between its original and final height. FJ is only willing to change the height of each hill by an integer amount.


##### PROGRAM NAME: skidesign


##### INPUT FORMAT:
Line 1:	The integer N.
Lines 2..1+N:	Each line contains the elevation of a single hill.
SAMPLE INPUT (file skidesign.in):

5
20
4
1
24
21

##### INPUT DETAILS:

FJ's farm has 5 hills, with elevations 1, 4, 20, 21, and 24.
OUTPUT FORMAT:
The minimum amount FJ needs to pay to modify the elevations of his hills so the difference between largest and smallest is at most 17 units.
Line 1:
SAMPLE OUTPUT (file skidesign.out):

18

##### OUTPUT DETAILS:

FJ keeps the hills of heights 4, 20, and 21 as they are. He adds mass to the hill of height 1, bringing it to height 4 (cost = 3^2 = 9). He shortens the hill of height 24 to height 21, also at a cost of 3^2 = 9. 

## Solution

1. Set up struct hills which stores its position and number of times that it has been moved.
2. Read INPUT into hill vector
3. Sort input vector.
4. Set up vectors start and end with beginning and end of hill vector
5. Begin infinite loop
6. Check if the distance between beginning and end is <= 17, if so break;
7. Check for hills to add to the end and start.
8. Check potential costs of incrementing start
9. Check potential costs of incrementing end
10. Compare costs and do the cheapest
11. end infinite loop
12. calculate total cost (sum of start and end costs)
13. print total cost and exit


