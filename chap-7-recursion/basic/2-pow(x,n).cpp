#include<bits/stdc++.h>
using namespace std;

// we have to compute x^n

double powerXtoNBrute(double x, int n) {
    long range = n;
    if(range < 0) {
        range = -1 * range;
    }
    double prod = 1.0;
    for(int i = 1; i <= range; i++) {
        prod *= x;
    }
    if(n >= 0) return prod;
    else return 1/prod;
} // correct but gives TLE since O(N) time and n can be till INT_MAX, so approx 2 billion operations

double powerXtoNOptimal(double x, int n) {
    // when n % 2 == 0, we do x * x and n = n / 2
    // when n % 2 == 1, we do ans = ans * x and n = n - 1 and when n == 0 we stop 
    long range = n;
    if(range < 0) {
        range = -1 * range;
    }
    double prod = 1.0;
    while(range) {
        if(range % 2 == 0) {
            x *= x; // when exponent is even we square the base and halve the exponent
            range = range / 2;
        } else {
            prod *= x; // when exponent in odd we remove one x, so that in the next iteration it will be halved again
            range--;
        }
    } 
    if(n >= 0) return prod;
    else return 1/prod; 
} // O(logN) time

int main() {
    
    return 0;
}