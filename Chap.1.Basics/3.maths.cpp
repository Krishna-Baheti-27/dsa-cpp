#include<bits/stdc++.h>
using namespace std;

void printDivisorsOptimised(int n) {
    // takes O(sqrt(n)) in place of O(n) but this does not print them in sorted order so maybe sort them by storing thme in a vector and sort it
    vector<int> lis;
    // instead of calling the sqrt() function repeatedly we use i*i <= n
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            lis.push_back(i);
            if(n/i != i) lis.push_back(n/i);
        }
    }
    sort(lis.begin(), lis.end()); // takes O(nlogn) here n is the number of factors and not the original n
    for(auto num : lis) cout << num << ' '; // takes O(n) where n is the number of factors and not the original n
    cout << '\n';
}

// a prime number is a number which has exactly two factors, one and itself
// hence 1 is not a prime number since it has only one factor which is 1

bool isPrimeBrute(int n) {
    if(n <= 1) return false;
    for(int i = 2; i <= n - 1; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

bool isPrimeOptimised(int n) {
    // for a composite number atleast one factor must exist till O(sqrt(n))
    // because we know the factors are i and n/ i when loop till i = 1 to i*i <= n
    if(n <= 1) return false;
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int gcdBrute(int a, int b) {
    // last common obtained factor
    for(int i = min(a,b); i >= 1; i--) {
        if(a % i == 0 && b % i == 0) return i; // if nothing is common then 1 would be the gcd here
    }
    return 1; // Technically unreachable, but good practice
}

int gcdOptimised(int a, int b) {
    // euclid algo is gcd(a,b) = gcd(a-b,b); where a > b
    // but for better time gcd(a,b) = gcd(a % b, b) where a > b
    if(a == 0) return b;
    if(b == 0) return a;
    if(a > b) return gcdOptimised(a % b, b);
    else return gcdOptimised(b % a, a);
}    

// better way to write
int gcdOptimisedBetter(int a, int b) {
    if (b == 0) return a;
    return gcdOptimised(b, a % b);
}
// since standard euclid algo works regardless of whether a is greater or b is greater

int iterativeGcdOptimised(int a, int b) {
    while(a != 0 && b != 0) {
        if(a > b) a = a % b;
        else b = b % a;
    }   
    if(a == 0) return b;
    else return a;
}

int iterativeGcdOptimisedBetter(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = b % a; // shrinking b, same as in recursive version
        a = temp; // now changing a to former b
    }
    return a;
}

int main() {
    cout << gcdOptimisedBetter(20,40) << endl;
    return 0;
}