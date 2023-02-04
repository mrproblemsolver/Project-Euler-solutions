/*
 https://projecteuler.net/problem=25
 */
#include <stdio.h>
int minlength = 1000;
char[] newfibo(char* a, char* b, int lena, int lenb) {
 int smallest = lena <= lenb ? lena : lenb;
 int biggest = smallest == lena ? lenb : lena;
 char ret[biggest + 1];
 int remain = 0;
 for (int i = 0; i < smallest; i++) {
  remain += (*a - '0') + (*b - '0');
  ret[i] = (remain % 10) + '0';
  remain -= remain % 10;
  remain /= 10;
  if (i != smallest - 1) {
   a++;
   b++;
   }
  }
 if (lena != lenb) {
  bool firstref = true;
  if (lena < lenb) {
   firstref = false;
   }
  for (int i = smallest; i < biggest; i++) {
   remain += (firstref ? *a : *b) - '0';
   ret[i] = (remain % 10) + '0';
   remain -= remain % 10;
   remain /= 10;
   if (i != biggest - 1) {
    if (firstref) {
     a++;
     }
    else {
     b++;
     }
    }
   }
  }
 a -= (lena - 1);
 b -= (lenb - 1);
 if (remain > 0) {
  ret[biggest] = remain + '0';
  }
 else {
  char retcopy[biggest];
  for (int i = 0; i < biggest; i++) {
   retcopy[i] = ret[i];
   }
  return retcopy;
  }
 return ret;
 }
char[] answer() {
 if (minlength == 1) return "1";
 if (minlength <= 0) return {};
 char *fibo1 = "1";
 int len1 = 1;
 char* fibo2 = "1";
 int len2 = 1;
 int lenret = 0;
 while (true) {
  char[] ret = newfibo(fibo1, fibo2, len1, len2);
  lenret = sizeof(ret)/sizeof(char);
  if (lenret >= minlength) return ret;
  fibo1 = &fibo2;
  fibo2 = &ret[0];
  len1 = len2;
  len2 = lenret;
  }
 return {};
 }
int main(void) {
 printf("%s", answer());
 return 0;
 }
