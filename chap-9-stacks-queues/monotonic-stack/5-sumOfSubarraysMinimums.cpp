#include<bits/stdc++.h>
using namespace std;

int sumSubarraysMinsBrute(vector<int> &arr) {
    int sum = 0;
    int mod = 1e9 + 7; // for large answers
    for(int i = 0; i < arr.size(); i++) {
        int minEl = arr[i];
        for(int j = i; j < arr.size(); j++) {
            minEl = min(minEl, arr[j]);
            sum = (sum + minEl) % mod;
        }
    }
    return sum;
} // O(N^2) time and O(1) space
  
int sumSubarraysMinsOptimal(vector<int> &arr) {

}

int main() {
    
    return 0;
}