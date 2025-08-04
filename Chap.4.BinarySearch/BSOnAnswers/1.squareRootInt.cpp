#include<bits/stdc++.h>
using namespace std;

int squareRootBrute(int n) {
    // return the floor value of square root of integer
    for(int i = 1; i <= n; i++) {
        if(i * i == n) return i;
        else if(i * i > n) return i - 1;
    }
}

int squareRootOptimal(int n) {
    int low = 1, high = n;
    long long ans = 1;
    while(low <= high) {
        long long mid = (low + high) / 2;
        if(mid * mid <= n) {
            ans = mid; // it could be my answer 
            low = mid + 1; // but looking for something better
        } else {
            high = mid - 1; // cannot be the answer in any case hence removing that space
        }
    }
    return ans;
}

int main() {
    
    return 0;
}