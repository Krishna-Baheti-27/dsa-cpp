#include<bits/stdc++.h>
using namespace std;

// return the elements which are occuring more than n / 3, times
// by basic maths we can figure that there can be atmax 2 elements satisfying this property

vector<int> majorityElementBrute(const vector<int> &arr) {
    vector<int> ans;
    for(int i  = 0; i < arr.size(); i++) {
        if(ans.size() == 0 || ans[0] != arr[i]) {
            int count = 0;
            for(int j = 0; j < arr.size(); j++) {
                if(arr[i] == arr[j]) count++;
            }
            if(count > arr.size() / 3) ans.push_back(arr[i]);
            if(ans.size() == 2) return ans;
        }
    }
    return ans;
} // O(n^n)

vector<int> majorityElementBetter(const vector<int> &arr) {
    unordered_map<int,int> mpp;
    vector<int> ans;
    for(int el : arr) mpp[el]++;
    for(auto el : mpp) if(el.second > arr.size() / 3) ans.push_back(el.first);
    return ans;
} // O(2N) time and O(N) space

vector<int> majorityElementMoreBetter(const vector<int> &arr) {
    unordered_map<int,int> mpp;
    vector<int> ans;
    for(int el : arr) {
        mpp[el]++;
        if(mpp[el] == arr.size() / 3 + 1) ans.push_back(el);
    } 
    return ans;
} // O(N) time and O(2N) space

vector<int> majorityElementOptimal(const vector<int> &arr) {
    vector<int> ans;
    int count1 = 0, count2 = 0, ans1 = INT_MIN, ans2 = INT_MIN;
    for(int i = 0; i < arr.size(); i++) {
        if(count1 == 0 && arr[i] != ans2) {
            count1 = 1; // could be our majority element
            ans1 = arr[i];
        } else if(count2 == 0 && arr[i] != ans1) {
            count2 = 1;
            ans2 = arr[i];
        } else if(arr[i] == ans1) {
            count1++;
        } else if(arr[i] == ans2) {
            count2++;
        } else {
            // if the element is none of our majority then we decrement both
            count1--;
            count2--;
        }
    }
    // do majority check, if ans1 and ans2 are actually majority elements
    count1 = 0, count2 = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == ans1) count1++;
        else if(arr[i] == ans2) count2++;
    }
    if(count1 > arr.size() / 3) ans.push_back(ans1);
    if(count2 > arr.size() / 3) ans.push_back(ans2);
    return ans;

// If a voter for ans1 shows up (el == ans1), ans1's vote count (count1) goes up. It has no effect on ans2.

// If a voter for ans2 shows up (el == ans2), ans2's vote count (count2) goes up.

// If a voter for a third party shows up (el is different), this new voter cancels out the influence of one voter from ans1 and one voter from ans2. So, both count1 and count2 decrease.
}

int main() {
    
    return 0;
}