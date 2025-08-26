#include<bits/stdc++.h>
using namespace std;

// find the subarray having max product and return it

int maxProductBrute(vector<int> &arr) {
    int maxProduct = INT_MIN; // smallest possible so any subarray product may overwrite it
    // generate all the subarrays and find the product of each and thus find the maximum prod subarray
    for(int i = 0; i < arr.size(); i++) {
        int prod = 1;
        for(int j = i; j < arr.size(); j++) {
            prod *= arr[j];
            maxProduct = max(maxProduct, prod);
        }
    }
    return maxProduct;
}

int maxProductOptimal(vector<int> &arr) {
    int prefix = 1, suffix = 1, maxProduct = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
        prefix *= arr[i];
        suffix *= arr[arr.size() - i - 1]; 
        maxProduct = max(maxProduct, max(prefix, suffix));
    }    
    return maxProduct;
}

int main() {
    
    return 0;
}