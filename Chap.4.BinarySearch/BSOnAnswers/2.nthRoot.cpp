#include<bits/stdc++.h>
using namespace std;

int nthRootOfNumBrute(int n, int num) {
    for(int i = 1; i <= num; i++) {
        int number = pow(i,n); // better than multiplying
        if(number == num) return i;
        else if(number > num) return -1; // nth root does not exist
    }
    return -1; // does not get executed
    // O(m * logn) since power takes logN time and m is num
}

int nthRootOfNumBrute(int n, int num) {
    int ans = 1; 
    for(int i = 1; i <= num; i++) {
        int number = pow(i, n);
        if(number == num) ans = number; // only have to find the exact value, not floor
        else if(number > num) break;
    }
    return ans;
}

// again here we can apply binary search on answers becuase we know that our answer will never exceed num, and here we have to find the value and not min or max possible answer (but still works)

int nthRootOfNumOptimal(int n, int num) {
    int low = 1, high = num;
    while(low <= high) {
        long long mid = (low + high) / 2;
        long long number = pow(mid, n);
        if(number == num) return mid;
        else if(number < num) {
            low = mid + 1; // look on the right, answer possible hence trim the left search space
        } else {
            high = mid - 1; // we try to reach the answer, since anything on the right cannot be my answer
            // answer not possible hence we trim the right search space
        }
    }
    return -1; // no answer possible
} // O(logm * logn) since we are applying binary search on m elements, and in each iteration we doing pow(mid, n) hence O(logN) time for that

// but this code fails for super large test cases since, pow(mid, n) will be huge but the trick is that we dont need to calculate exact value of pow(mid, n) since thats irrelevant, what we need is to just find out whether pow(mid, n) is lesser/equal/ greater than m, and once we find that lets say its greater, we stop our computation right there without finding its complete value

int isPossible(int mid, int n, int num) {
    long long ans = 1;
    for(int i = 1; i <= n; i++) {
        ans = ans * mid;
        if(ans > num) return 0; // not possible
    }
    if(ans == num) return 1; // our answer
    else if(ans < num) return 2; // look on the right
}

int nthRootOfNumMostOptimal(int n, int num) {
    int low = 1, high = num;
    while(low <= high) {
        long long mid = (low + high) / 2;
        int whatToDo = isPossible(mid, n, num);
        if(whatToDo == 1) return mid; // our answer
        else if(whatToDo == 2) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // no nth root exists
}

int main() {
    
    return 0;
}