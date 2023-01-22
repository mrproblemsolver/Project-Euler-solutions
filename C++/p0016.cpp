/*
    2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
    What is the sum of the digits of the number 2^1000?
    */
#include <iostream>
#include <vector>
using namespace std;

int number = 2;
int pow = 1000;
string answer() {
    vector<int> retmatrix;
    retmatrix.push_next(1);
    int matrixlen = 0;
    int subtotal = 0;
    for (int i = 0; i < pow; i++) {
        subtotal = 0;
        vector<int> subnumbers;
        for (int j = 0; j < matrixlen; j++) {
            subtotal += retmatrix[j] * number;
            retmatrix[j] = subtotal % 10;
            subtotal -= subtotal % 10;
            subtotal /= 10;
            }
        while (subtotal > 0) {
            retmatrix.push_next(subtotal % 10);
            matrixlen++;
            subtotal -= subtotal % 10;
            subtotal /= 10;
            }
        }
    int ret = 0;
    for (int i = 0; i < matrixlen; i++) {
        ret += retmatrix[i];
        }
    return ret;
    }
int main() {
    cout << answer() << endl;
    }
