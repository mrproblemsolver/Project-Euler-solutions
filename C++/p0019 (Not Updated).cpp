/*
 https://projecteuler.net/problem=19
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> firstdate = {1, 1, 1900};
int firstdow = 1;
int totaldom[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int targetdow = 1;
int targetcentury = 20;
bool isextraday(int year) {
 if (year % 4 == 0) {
  if (year % 400 == 0) return true;
  }
 return false;
 }
bool isfuturedate(vector<int> referencedate, vector<int> comparingdate) {
 if (referencedate [2] > comapringdate[2]) {
  return true;
  }
 else if (referencedate [2] == comparingdate[2]) {
  if (referencedate[1] > comparingdate [1]) {
   return true;
   }
  else if (referencedate [1] == comparingdate [1]) {
   if (referencedate [0] > comparingdate [0]) {
    return true;
    }
   }
  }
 return false;
 }
int nextheadofmonth(vector<int> referencedate, int dow) {
 int retdow = dow;
 if (referencedate[1] != 2) {
  retdow += totaldom[referencedate[1] - 1] - 1;
  }
 else {
  retdow += (isextraday(referencedate[2]) ? 1 : 0) + totaldom[1] - 1;
  }
 retdow = retdow % 7;
 retdow++;
 referencedate[1]++;
 if (referencedate[1] > 12) {
  referencedate[1] = 1;
  referencedate[2]++;
  }
 return retdow;
 }
int answer() {
 vector<int> targetfirstdate = {1, 1, ((targetcentury - 1) * 100) + 1};
 vector<int> targetseconddate = {totaldom[11], 12, targetcentury * 100};
 vector<int> indexdate;
 int indexdow = firstdow;
 for (int i = 0; i < 3; i++) indexdate.push_back(firstdate[i]);
 while (isfuturedate(targetfirstdate, indexdate)) {
  indexdow = getheadofmonth(indexdate, indexdow);
  }
 int ret = 0;
 while (isfuturedate(targetseconddate, indexdate) {
  if (indexdow == 7) ret++;
  indexdow = getheadofmonth(indexdate, indexdow);
  }
 return ret;
 }
int main() {
 cout << answer() << endl;
 }
