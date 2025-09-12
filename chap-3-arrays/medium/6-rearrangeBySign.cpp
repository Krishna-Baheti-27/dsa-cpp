#include<bits/stdc++.h>
using namespace std;

// we have array of even size having equal number of positive and negative numbers
// variety 1
vector<int> rearrangeArrayBrute(vector<int> &arr) {
    vector<int> posArr;
    vector<int> negArr;
    for(int el : arr) {
        if(el > 0) posArr.push_back(el);
        else negArr.push_back(el);
    }
    for(int i = 0; i < arr.size() / 2; i++) {
       arr[2*i] = posArr[i];
       arr[2*i + 1] = negArr[i];
    }
    return arr;
} // O(n + n / 2) time and O(n) space

// we have array of even size having equal number of positive and negative numbers
// variety 1

vector<int> rearrangeArrayOptimal(vector<int> &arr) {
    // we cant improve the space as you will have to remember the order of elements as well, but we can do this in single pass
    vector<int> ans(arr.size(), 0);
    int pos = 0, neg = 1;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > 0) {
            ans[pos] = arr[i];
            pos += 2;
        } else {
            ans[neg] = arr[i];
            neg += 2;
        }
    }
    return ans; // O(N) time and O(N) space
}

// variety 2
// if any of the positive or negative numbers are left, then we add them to the end without altering their order

vector<int> rearrangeArrayOptimalVar2(vector<int> &arr) {
    // here since the positives are not equal to negatives, we do not know whether positives are greater or negatives are greater or whether they are equal
    // so we fall back to our brute force solution which handles all cases
    vector<int> posArr;
    vector<int> negArr;
    for(int el : arr) {
        if(el > 0) posArr.push_back(el);
        else negArr.push_back(el);
    }
    // two pointer style not brute force style
    int i = 0, j = 0, k = 0;
    while(i < posArr.size() && j < negArr.size()) {
        if(k % 2 == 0) {
            arr[k] = posArr[i];
            i++;
        } else {
            arr[k] = negArr[j];
            j++;
        }
        k++;
    }
    while(i < posArr.size()) {
        arr[k++] = posArr[i++];
    }
    while(j < negArr.size()) {
        arr[k++] = negArr[j++];
    }
    return arr; // we used all of our elements in posArr and negArr and hence done
    // O(2n) time and O(n) space
}

vector<int> rearrangeArrayOptimalVar2AnotherMethod(vector<int> &arr) {
    // exactly like brute force style
    vector<int> posArr;
    vector<int> negArr;
    for(int el : arr) {
        if(el > 0) posArr.push_back(el);
        else negArr.push_back(el);
    }
    // now we simply fill based on the which array is better, once either one is exhausted we append the leftovers
    if(posArr.size() > negArr.size()) {
        int i;
        for(i = 0; i < negArr.size(); i++) {
            arr[2*i + 1] = negArr[i];
            arr[2*i] = posArr[i];
        }
        // for left overs
        while(i < posArr.size()) {
            arr[i] = posArr[i];
            i++;
        }
    } else {
        int i;
        for(i = 0; i < posArr.size(); i++) {
            arr[2*i + 1] = negArr[i];
            arr[2*i] = posArr[i];
        }
        // for left overs
        while(i < negArr.size()) {
            arr[i] = negArr[i];
            i++;
        }
    }
    return arr;
} // O(2N) time and O(N) space

int main() {
    
    return 0;
}