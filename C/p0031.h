/*
 https://projecteuler.net/problem=31
 */
#include <stdio.h>
int targetpence = 200;
int availablepences[5] = {100, 50, 20, 5, 2, 1};
int answer() {
 int pencetypes = sizeof(availablepences)/sizeof(int);
 int selectedpences[pencetypes];
 int ret = 0;
 int index = pencetypes - 1;
 int maxindex = index;
 int totalpence = 0;
 bool OK = false;
 int jumper = 0;
 int minremain = 0;
 while (!OK) {
  while (totalpence < targetpence) {
   minremain = (targetpence - totalpence) % availablepences[index];
   jumper = ((targetpence - totalpence) - minremain) / availablepences[index];
   if (jumper == 0) {
    jumper = 1;
    }
   else if (minremain > 0) {
    jumper++;
    }
   selectedpences[index] += jumper;
   totalpence += availablepences[index] * jumper;
   }
  while (totalpence == targetpence) {
   ret++;
   selectedpences[index] = 1;
   totalpence++;
   }
  while (totalpence > targetpence) {
   while (selectedpences[index] == 0) index--;
   if (index == 0) {
    OK = true;
    }
   else {
    totalpence -= selectedpence[index] * availablepences[index];
    selectedpence[index] = 0;
    index--;
    selectedpence[index]++;
    totalpence += availablepences[index];
    index = maxindex;
    }
   }
  }
 return ret;
 }
int main(void) {
 printf("%d", answer());
 return 0;
 }
