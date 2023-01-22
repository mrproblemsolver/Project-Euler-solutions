/*
    If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
    If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
    NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
    */
#include <iostream>
using namespace std;

int minnumber = 1;
int maxnumber = 1000;
int answer() {
    int level1[9] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
    int level1_5[8] = {6, 6, 8, 8, 7, 7, 9, 9, 8};
    int level2[8] = {3, 6, 6, 6, 5, 5, 7, 7, 6};
    int level3 = 7;
    int levelother[2] = {0, 8};
    int level = 0;
    int tmp = 0;
    int tmp2 = 0;
    int tmp3 = 0;
    int ret = 0;
    for (int i = minnumber; i <= maxnumber; i++) {
        level = 0;
        tmp = i;
        while (tmp > 0) {
            tmp2 = tmp % 1000;
            tmp -= tmp % 1000;
            tmp /= 1000;
            ret += levelother[level];
            if (tmp2 != 0) level++;
            tmp3 = tmp2 % 100;
            if (tmp3 < 20 && tmp3 > 10) {
                ret += level1_5[tmp3 % 10];
                }
            else if (tmp3 >= 10) {
                ret += level2[(tmp3 - (tmp3 % 10)) / 10];
                }
            tmp3 = tmp2;
            if (tmp3 >= 100) {
                ret += level1[(tmp3 - (tmp3 % 100)) / 100];
                ret += level3;
                }
            if (tmp3 % 10 > 0 && (tmp3 % 100 >= 20 || tmp3 >= 100)) {
                ret += level1[tmp3 % 10];
                }
            }
        }
    if (maxnumber - minnumber > 1) ret += 3;
    return ret;
    }
int main() {
    cout << answer() << endl;
    }
