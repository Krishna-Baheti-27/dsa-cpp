#include <bits/stdc++.h>
using namespace std;

// every number appears twice except a single number return that

///////////////////////////////////////////////////////////////////////////////////

// so we just take xor of all, the pairs get cancelled and we get the single number

int singleNumber(vector<int> &arr) {

    int xor1 = 0;

    for(int i = 0; i < arr.size(); i++) {
        xor1 ^= arr[i];
    }

    return xor1;

} // O(N) time and O(1) space

int main() {
    
    return 0;
}