#include<bits/stdc++.h>
using namespace std;

int squareRootBrute(int n) {
    // return the floor value of square root of integer
    for(int i = 1; i <= n; i++) {
        if(i * i == n) return i;
        else if(i * i > n) return i - 1;
    }
}

int squareRootBruteUsingAnswer(int n) {
    int ans = 1;
    for(int i = 1; i <= n; i++) { // answer cannot exceed n
        if(i *i <= n) ans = i;
        else break;
    }
    return ans;
    // whenever we have this sort of questions, where answer is possible for some values and later it is not possible, we can apply binary search on answers
}


// using binary search on answers
int squareRootOptimal(int n) {
    int low = 1, high = n;
    long long ans = 1;
    while(low <= high) {
        long long mid = (low + high) / 2;
        if(mid * mid <= n) {
            ans = mid; // it could be my answer 
            low = mid + 1; // but looking for something better
            // if answee possible we trim the left search space
        } else {
            high = mid - 1; // if answer not possible, then remove the right search space
        }
    }
    return ans;
}

// so whenever you know that the answer is within a range, here from 1 to n, and they are asking for min or max then always apply binary search on answers

int main() {
    
    return 0;
}