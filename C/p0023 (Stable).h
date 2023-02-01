/*
 A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 
 A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
 
 As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
 
 Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
 */
#include <stdio.h>
int limit = 28123;
long int answer() {
 long int ret = 1;
 int tmp = 0;
 int loop = 0;
 bool isdeficient = false;
 for (int i = 2; i <= limit; i++) {
  tmp = 0;
  loop = (i % 2 == 0) ? (i / 2) : ((i % 3 == 0) ? (i / 3) : (i - (i % 3)) / 3);
  isdeficient = true;
  for (int j = 1; j <= loop; j++) {
   if (i % j == 0) {
    tmp += j;
    if (j != 1) {
     loop = i / j;
     tmp += loop - 1;
     }
    if (tmp > i) {
     isdeficient = false;
     break;
     }
    }
   if (isdeficient) {
    ret += i;
    }
   }
  }
 return ret;
 }
int main(void) {
 printf("%d", answer());
 return 0;
 }
