#include<bits/stdc++.h>
using namespace std;

int majorityElementBrute(vector<int> &arr) { // O(N^2)
    for(int i = 0; i < arr.size(); i++) {
        // for each element arr[i] we find its frequency by using an extra loop and then we check if its greate than n / 2 then its a majority element else not
        int maj = arr[i], majFreq = 0;
        for(int j = 0; j < arr.size(); j++) {
            if(arr[j] == maj) majFreq++;
        }
        if(majFreq > arr.size() / 2) return maj;
    }
    return -1; // no majority
}

// int majorityElementBetter(vector<int> &arr) { // O(N) time and space
//     unordered_map<int,int> mp;
//     for(int i = 0; i < arr.size(); i++) mp[arr[i]]++;
//     for(int i = 0; i < arr.size(); i++) {
//         if(mp[arr[i]] > arr.size() / 2) return arr[i];
//     }
//     return -1; // no majority
// } // the two loops are just for readability but we can check fo majortiy in single pass, basically store fequency and check

int majorityElementBetter(vector<int> &arr) {
    unordered_map<int,int> mp;
    int n = arr.size();
    for(int num : arr) {
        mp[num]++;
        if(mp[num] > n / 2) return num;
    }
    return -1;
}

int majorityElementOptimal(vector<int> &arr) {
    // step 1 => apply moores voting algo
    // step 2 => find if the element is actually majority element
    int majEl, count = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(count == 0) { // vvip is that we only change the majority element if count = 0 (or it has been cancelled by other elements)
            majEl = arr[i];
            count++;
        } else if(arr[i] == majEl) count++;
        else count--;
    }
    count = 0;
    // no need to check this if you are guranteed to have a majority element
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == majEl) count++;
    }
    if(count > arr.size() / 2) return majEl; // this just verifies if chosen element is majority element
    return -1;
}

int main() {
    vector<int> arr = {2,2,1,1,1,2,2};
    cout << majorityElementOptimal(arr) << endl;
    return 0;
}