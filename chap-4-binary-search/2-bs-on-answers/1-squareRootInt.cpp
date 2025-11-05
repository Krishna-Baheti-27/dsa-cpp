#include<bits/stdc++.h>
using namespace std;

// given an integer n, we have to return the floor value of the square root of the n 

/////////////////////////////////////////////////////////////////////////////////

// the brute force involves starting from 1 till n and then checking if each if square of i is equal to n, if yes then i is the square root of n, if we exceed the value of of n then we simply return i - 1 as (i - 1) ^ 2 will be lesser than n and so i - 1 is the floor value of square root of n

int squareRootBrute(int n) {
    
    for(int i = 1; i <= n; i++) {
        if(i * i == n) return i;
        else if(i * i > n) return i - 1;
    }

} // O(N) time in worst case (although loop will really run for probably O(sqrt(n)) times)

///////////////////////////////////////////////////////////////////////////////

// whenever we have the case or possibility that there is an answer possible in a certain range and after which there is no answer possible then we can apply binary search on answer

// solving the above problem using linear search but by maintaing the answer approach

int squareRootBruteUsingAnswer(int n) {

    int ans = 1;

    for(int i = 1; i <= n; i++) { // answer cannot exceed n
        if(i *i <= n) ans = i; // can be answer but look for better
        else break;
    }

    return ans;

} // O(N) time

///////////////////////////////////////////////////////////////////////////////

// now the optimal solution using the same approach and considering low = 1 (min possible value of answer) and high = n (max possible value of answer)

int squareRootOptimal(int n) {

    int low = 1, high = n;
    long long ans = 1; // to avoid overflow

    while(low <= high) {

        long long mid = (low + high) / 2;

        if(mid * mid <= n) {
            ans = mid; // it could be my answer 
            low = mid + 1; // but looking for something greater hence trim the left search space
        } else {
            high = mid - 1; // answer is not possible since it has exceeded n so trim right
        }
    }

    return ans;

} // O(logn) time

// so whenever you know that the answer is within a range, here from 1 to n, and they are asking for min or max then always apply binary search on answers

int main() {
    
    return 0;
}