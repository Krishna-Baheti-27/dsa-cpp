#include<bits/stdc++.h>
using namespace std;

int nthRootOfNumBrute(int n, int num) {
    for(int i = 1; i <= num; i++) {
        int number = pow(i,n);
        if(number == num) return i;
        else if(number > num) return -1; // nth root does not exist
    }
    return -1; // does not get executed
    // O(m * logn) since power takes logN time and m is num
}

int nthRootOfNumOptimal(int n, int num) {
    int low = 1, high = num;
    while(low <= high) {
        long long mid = (low + high) / 2;
        long long number = pow(mid, n);
        if(number == num) return mid;
        if(number < num) {
            low = mid + 1; // look on the right
        } else {
            high = mid - 1; // we try to reach the answer, since anything on the right cannot be my answer
        }
    }
    return -1; // no answer possible
}

int main() {
    
    return 0;
}