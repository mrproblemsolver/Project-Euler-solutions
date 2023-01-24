/*
    n! means n × (n − 1) × ... × 3 × 2 × 1
    
    For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
    and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
    
    Find the sum of the digits in the number 100!
    */
#include <iostream>
#include <vector>
using namespace std;

int factorial = 100;
int answer() {
    vector<int> retmatrix;
    retmatrix.push_next(1);
    int matrixlength = 1;
    int remain = 0;
    for (int i = 2; i <= factorial; i++) {
        for(int j = 0; j < matrixlength; j++) {
            remain += i * retmatrix[j];
            retmatrix[j] = remain % 10;
            remain -= remain % 10;
            remain /= 10;
            }
        int tmp = 0;
        while (remain > 0) {
            tmp = remain % 10;
            retmatrix.push_next(tmp);
            remain -= tmp;
            remain /= 10;
            matrixlength++;
            }
        }
    int ret = 0;
    for (int i = 0; i < matrixlength; i++) {
        ret += retmatrix[i];
        }
    return ret;
    }
int main() {
    cout << answer() << endl;
    }
