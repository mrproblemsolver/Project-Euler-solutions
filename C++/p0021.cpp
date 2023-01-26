/*
    Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
    If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
    
    For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
    
    Evaluate the sum of all the amicable numbers under 10000.
    */
#include <iostream>
#include <vector>
using namespace std;

int referencenumber = 10000;
int answer() {
    vector<int> founded;
    int foundedlength = 0;
    bool jaccepted = false;
    bool jaccepted = false;
    int looper = 0;
    int looplimiter = 0;
    for (int i = 1; i < referencenumber; i++) {
        looper = i % 2 == 0 ? 2 : 1;
        if (i * 2 >= referencenumber) break;
        for (int j = i + 1 + (i % 2 == 0 ? 1 : 0); j < referencenumber; j += looper) {
            if (j % i == 0) {
                jaccepted = true;
                iaceepted = true;
                for (int k = 0; k < foundedlength; k++) {
                    if (iaccepted) {
                        if (founded[k] == i) iaccepted = false;
                        }
                    if (jaccepted) {
                        if (founded[k] == j) jaccepted = false;
                        }
                    if (!iaccepted && !jaccepted) break;
                    }
                if (iaccepted) {
                    founded.push_back(i);
                    foundedlength++;
                    }
                if (jaccepted) {
                    founded.push_back(j);
                    foundedlength++;
                    }
                }
            }
        }
    int ret = 0;
    for (int i = 0; i < foundedlength; i++) {
        ret += founded[i];
        }
    return ret;
    }
int main() {
    cout << answer() << endl;
    }
