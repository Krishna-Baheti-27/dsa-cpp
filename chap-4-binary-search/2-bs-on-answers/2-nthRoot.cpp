#include<bits/stdc++.h>
using namespace std;

// the problem is nth root of num, if it exists then return it else return -1 if doesnt exist, unlike returniing the floor value in case of square root 

////////////////////////////////////////////////////////////////////////////////////

// the brute force using linear search where we first pick up 1 and multiply it n times to see if it equals num or not, to do in less time we use binary exponentiation and do i^n in logn time

int nthRootOfNumBrute(int n, int num) {

    for(int i = 1; i <= num; i++) {

        int number = pow(i,n); // better than multiplying
        if(number == num) return i;
        else if(number > num) return -1; // nth root does not exist

    }

    return -1; // to avoid warnings
    
} // O(num * logn) since power takes logN time 

/////////////////////////////////////////////////////////////////////////////////

// same linear search solution using the answer approach so we have better clarity

int nthRootOfNumBrute(int n, int num) {

    int ans = 1; 

    for(int i = 1; i <= num; i++) {

        int number = pow(i, n);
        if(number == num) ans = number; // only have to find the exact value, not floor
        else if(number > num) break;
    }

    return ans;

} // O(num * logn) time

/////////////////////////////////////////////////////////////////////////////

// again here we can apply binary search on answers becuase we know that our answer will never exceed num, and here we have to find the value and not min or max possible answer (but still works)

int nthRootOfNumOptimal(int n, int num) {

    int low = 1, high = num; // to mark the range of answer

    while(low <= high) {

        long long mid = (low + high) / 2;
        long long number = pow(mid, n);

        if(number == num) return mid;
        else if(number < num) {
            low = mid + 1; // we have to increase the value of number, hence eliminate left 
        } else {
            high = mid - 1; // we have to decrease the value of number, hence eliminate right
        }
    }

    return -1; // no answer possible

} // O(log(num) * logn) time since total log(num) iteration and work done in each iteration is logn

////////////////////////////////////////////////////////////////////////////////

// but this code can be optimised a little bit more as it fails for large test cases
// This code fails for super large test cases since, pow(mid, n) will be huge but the trick is that we dont need to calculate exact value of pow(mid, n) since thats irrelevant, what we need is to just find out whether pow(mid, n) is lesser/equal/greater than m, and once we find that at any instance the value of pow(mid, n) exceeds num we stop our computation right there without finding its complete value since that wont matter as we already know that no answer is possible

int isPossible(int mid, int n, int num) {

    long long ans = 1;

    // we have to find mid^n but smartly by signaling whether its possible or not

    for(int i = 1; i <= n; i++) {
        ans = ans * mid; 
        if(ans > num) return 0; // not possible
    }

    if(ans == num) return 1; // our answer
    else if(ans < num) return 2; // look on the right, we are too small rn

}

int nthRootOfNumMostOptimal(int n, int num) {

    int low = 1, high = num;

    while(low <= high) {

        long long mid = (low + high) / 2;

        int whatToDo = isPossible(mid, n, num);

        if(whatToDo == 1) {
            return mid; // our answer
        } else if(whatToDo == 2) {
            low = mid + 1; // increase the value by trimming left
        } else {
            high = mid - 1; // we have exceeded and hence trim right to lower the value
        }
    }

    return -1; // no nth root exists

} // O(log(num) * n) time since here we cant apply binary exponentiation and take O(n) time to find the product  

int main() {
    
    return 0;
}