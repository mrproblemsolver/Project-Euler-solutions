#include <iostream>
using namespace std;

//https://projecteuler.net/problem=12

long int dividercountertolerance = 500;
long int tau(long int num) {
    long int n = num;
    long int i = 2;
    long int p = 1;
    if (num == 1) return 1;
    while (i * i <= n) {
        long int c = 1;
        while (n % i == 0) {
            n /= i;
            c++;
        }
        i++;
        p *= c;
    }
    if (n == num || n > 1)
        p *= 1 + 1;
    return p;
}
long int answer() {
    long int n = 1;
    long int d = 1;
    while (tau(d) <= dividercountertolerance) {
        n++;
        d += n;
    }
    return d;
}
int main() {
    cout << answer() << endl;
}
