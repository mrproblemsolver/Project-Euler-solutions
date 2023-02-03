/*
 Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
 
 For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
 
 What is the total of all the name scores in the file?
 */
#include <stdio.h>
#include <stdlib.h>
char escapes[2] = {'\"', ','};
char* datastream;
int datalength = 0;
int *startindexes;
int *endindexes;
int *sorted;
int sortedlength = 0;
int sortedindex = 0;
int letterbase = 0;
int streamlength = 0;
void AddSorted(int* ref, int val) {
 sorted += (sortedlength - sortedindex);
 *sorted = val;
 sortedindex = 0;
 sorted -= sortedlength;
 sortedlength++;
 }
int[] GetIndexes(int index) {
 startindexes += index;
 endindexes += index;
 int ret[2] = {*startindexes, *endindexes};
 startindexes -= index;
 endindexes -= index;
 return ret;
 }
void ExchangeSorted(int index) {
 sorted -= sortedindex;
 sorted += index;
 int tmp = *sorted;
 sorted--;
 int tmp2 = *sorted;
 *sorted = tmp;
 sorted++;
 *sorted = tmp2;
 sorted -= index;
 sortedindex = 0;
 }
char[] GetValue(int start, int end) {
 char ret[end - start + 1];
 int i = start;
 datastream += start;
 int retindex = 0;
 for (; i <= end; i++) {
  ret[retindex] = *datastream;
  datastream++;
  }
 datastream -= i;
 return ret;
 }
void loaddatastream() {
 letterbase = 'A' - '0';
 //Download datastream and datalength
 //here
 for (int i = 0; i < datalength; i++) {
  if (*datastream == escapes[0]) {
   streamlength++;
   }
  if (i != datalength - 1) datastream++;
  }
 if (datalength > 1) datastream -= (datalength - 1);
 streamlength /= 2;
 }
void loadnamestream() {
 startindexes = (int*)malloc(sizeof(int));
 endindexes = (int*)malloc(sizeof(int));
 for (int i = 0; i < datalength; i++) {
  if (*datastream == escapes[0]) {
   if (*startindexes == 0) {
    *startindexes = i + 1;
    }
   else {
    *endindexes = i - 1;
    if (i != datalength - 1) {
     startindexes++;
     endindexes++;
     }
    }
   }
  }
 startindexes -= streamlength - 1;
 endindexes -= streamlength - 1;
 }
bool issmallerthan(int index) {
 int str1[] = GetIndexes(index);
 int str2[] = GetIndexes(index - 1);
 char tmp1[] = GetValue(str1[0], str1[1]);
 char tmp2[] = GetValue(str2[0], str2[1]);
 int ref1 = str1[1] - str1[0] + 1;
 int ref2 = str2[1] - str2[0] + 1;
 bool ret = ref1 < ref2;
 int looplimiter = ref1 < ref2 ? ref1 : ref2;
 for (int i = 0; i < looplimiter; i++) {
  if ((tmp1[i] - '0') > (tmp2[i] - '0')) return false;
  }
 return ret;
 }
int total(int index) {
 int str[] = GetIndexes(index);
 char tmp[] = GetValue(str[0], str[1]);
 int len = tmp[1] - tmp[0] + 1;
 int ret = 0;
 for (int i = 0; i < len; i++) {
  ret += (tmp[i] - '0') - letterbase;
  }
 ret += len;
 return ret;
 }
long int answer() {
 loaddatastream();
 loadnamestream();
 sorted = (int*)malloc(sizeof(int));
 *sorted = 0;
 for (int i = 1; i < namestream; i++) {
  AddSorted(sorted, i);
  for (int j = i; j > 0; j--) {
   if (issmallerthan(j)) {
    ExhangeSorted(j);
    }
   else {
    break;
    }
   }
  }
 long int ret = 0;
 for (int i = 0; i < sortedlength; i++) {
  ret += (total(i)) * (i + 1));
  }
 return ret;
 }
int main(void) {
 printf("%d", answer());
 return 0;
 }
