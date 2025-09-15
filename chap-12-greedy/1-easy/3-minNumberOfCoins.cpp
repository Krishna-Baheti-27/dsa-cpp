#include<bits/stdc++.h>
using namespace std;

// int findMinCoinsIncorrect(int n) {
//     vector<int> arr = {1,2,5,10,20,50,100,500,1000};
//     int noOfCoins = 0;
//     int i = arr.size() - 1;
//     while(i >= 0) {
//         if(arr[i] > n) i++;
//         else if(arr[i] == n) return 1;
//         else {
//             n -= arr[i];
//             noOfCoins++;
//         }
//     }
//     return noOfCoins;
// }

int findMinCoins(int n) {
    vector<int> arr = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int noOfCoins = 0;
    for (int i = arr.size() - 1; i >= 0; i--) {
        // While the current coin can be used
        while (n >= arr[i]) {
            n -= arr[i];        // Subtract the coin's value
            noOfCoins++;        // Increment the coin count
        }
    }
    return noOfCoins;
} // O(V) time in worst case

vector<int> findMinDenominations(int n) {
    vector<int> arr = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    vector<int> deno;
    for(int i = arr.size() - 1; i >= 0; i--) {
        while(n >= arr[i]) {
            n -= arr[i];
            deno.push_back(arr[i]);
        }
    }
    return deno;
} // O(V) time in worst case

// try a harder version on leetcode

int main() {
    
    return 0;
}