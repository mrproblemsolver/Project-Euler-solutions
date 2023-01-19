#include <iostream>
using namespace std;

/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

long int reference = 600851475143;
long int answer() {
    long int i = 2;
    long int n = reference;
    while (n % i == 0) n = n / i;
    i = 3;
    while ((i * i) <= n) {
         while (n % i == 0)  n = n / i;
         i += 2;
    }
    return n;
}

int main()
{
    cout << answer() << "\n";
}
