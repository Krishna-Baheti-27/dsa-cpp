#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater2Brute(const vector<int> &arr) {
    vector<int> ans;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        // for each element, look for the whole array in circular fashion and if you still dont find it then -1
        int index;
        int j;
        for(j = i + 1; j < i + n; j++) {
            index = j % n;
            if(arr[index] > arr[i]) break;
        }
        if(j < i + n - 1) ans.push_back(arr[index]);
        else ans.push_back(-1);
    }
    return ans;
}

int main() {
    
    return 0;
}