#include <iostream>
using namespace std;

//https://projecteuler.net/problem=14

long int docount = 1000000;
long int answer() {
    long int tmp = 0;
    int counter = 0;
    int longest = 0;
    long int ret = 0;
    for (long int i = 2; i < docount; i++) {
        counter = 1;
        for (tmp = i; tmp > 1; counter++) {
            if (tmp % 2 == 1) tmp /= 2;
            else tmp = (tmp * 3) + 1;
        }
        if (counter > longest) {
            longest = counter;
            ret = i;
        }
    }
    return ret;
}

int main()
{
	cout << answer() << endl;
}
