#include<bits/stdc++.h>
using namespace std;

int isSingleBrute(vector<int> &arr) {
    // O(N^2) solution
    for(int i = 0; i < arr.size(); i++) {
        bool flag = false;
        for(int j = 0; j < arr.size(); j++) {
            if(j != i && arr[j] == arr[i]) flag = true; // second occurence found
        }
        if(flag == false) return arr[i]; // no second occcurence hence arr[i] is the single element
    }
    return -1; // unreachable
}

int isSingleBetter(vector<int> &arr) { // using hashing
    // here we have used unordered_map but you can also use map or hash array
    // there is a tradeoff between size nad speed
    unordered_map<int,int> mp;
    for(int num : arr) mp[num]++;
    for(int num : arr) if(mp[num] == 1) return num;
    return -1; // no single element
} 

int isSingleOptimal(const vector<int> &arr) {
    int xor1 = 0; // pointer to find the position of single element
    for(int i = 0; i < arr.size(); i++) {
        xor1 = xor1 ^ arr[i];
    }
    // pretty easy logic, a ^ a = 0 and a ^ 0 = 0, hence when we find xor of all elements, the one which is single will not get cancelled and hence it works
    return xor1;
}

int main() {
    
    return 0;
}