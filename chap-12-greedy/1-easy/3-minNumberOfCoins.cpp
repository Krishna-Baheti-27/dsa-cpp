#include<bits/stdc++.h>
using namespace std;

// we are given an array of coins and also the value for which we have to create change for.
// our task is to use the min number of coins possible to generate the value

/////////////////////////////////////////////////////////////////////////////////////

// so we start from biggest (this is our greedy approach to minimise the number of coins) and then we keep using the same coin till n >= it, and if not then we take new coin and each time when we reduce the value of n we do coins++ so we keep track of number of coins used

int findMinCoins(int n) {

    vector<int> arr = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    int noOfCoins = 0;

    for (int i = arr.size() - 1; i >= 0; i--) {

        // While the current coin can be used

        while(n >= arr[i]) {
            n -= arr[i];        // Subtract the coin's value
            noOfCoins++;        // Increment the coin count
        }
    }

    return noOfCoins;

} // O(n) time in worst case when use only 1 ruppee coins to generate n

//////////////////////////////////////////////////////////////////////////////////

// when you have to return which coins you used and how much, the logic remains same

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

} // O(n) time in worst case when use only 1 ruppee coins to generate n

////////////////////////////////////////////////////////////////////////////////

// the above version fails when we have sum of any two denominatios exceeding other denomination
// Example here : {1, 2, 5, 10, 20, 50, 100, 500, 1000}
// 1 + 2 < 5, 2 + 5 < 10 and 10 + 20 < 50 and so on
// in this case our greedy approach works

// but if we have denominations like this
// {1, 5, 6, 9} 
// here 5 + 6 > 9 so our approach would fail
// Eg: for n = 11, our approach would give 9 ,1, 1 and optimal is 6, 5

// so in real life denominations are created keeping in mind this mathematical logic so that greedy algo is applicable

int main() {
    
    return 0;
}