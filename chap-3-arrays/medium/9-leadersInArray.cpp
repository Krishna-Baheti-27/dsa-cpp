#include<bits/stdc++.h>
using namespace std;

// a leader is an element in an array which is greater than all the elements present on its right, the last element is always the leader

vector<int> printLeadersBrute(const vector<int> &arr) {
    // for each element we check it is greater than every element on its right, if it is we mark it as a leader, also handles the case of last element which is always a leader
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++) {
        bool flag = true;
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] > arr[i]) {
                flag = false;
                break;
            }
        }
        if(flag) ans.push_back(arr[i]);
    }
    return ans;
}

vector<int> printLeadersOptimal(const vector<int> &arr) {
    int max = INT_MIN;
    vector<int> ans;
    for(int i = arr.size() - 1; i >= 0; i--) {
        if(arr[i] > max) {
            max = arr[i];
            ans.push_back(arr[i]); 
            // arr[i] is a leader if it is greater than the greatest element encountered so far from the right since thats how we defined the leader to be
        }
    }   
    return ans;
}

int main() {
    vector<int> arr = {10,22,12,3,0,6};
    vector<int> ans = printLeadersBrute(arr);
    for(int num : ans) cout << num << ' ';
    cout << endl;
    vector<int> ans2 = printLeadersOptimal(arr);
    for(int num : ans2) cout << num << ' ';
    return 0;
}