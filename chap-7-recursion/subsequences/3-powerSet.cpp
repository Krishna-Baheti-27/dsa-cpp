#include<bits/stdc++.h>
using namespace std;

// power set or print all subsequences, (need not be contiguous but have to be a subset of string)
// s = "abc", => '', a ,b, c, ab ,bc, ca, abc, at max 8 subsets or subsequences

vector<vector<int>> subsets(vector<int> &arr) {
    vector<vector<int>> ans;
    int power = pow(2,arr.size());
    for(int i = 0; i < power; i++) {
        vector<int> temp;
        for(int j = 0; j < arr.size(); j++) {
            if((arr[j] & (1 << i)) != 0) temp.push_back(arr[j]); // take this since bit is set
        }
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    
    return 0;
}