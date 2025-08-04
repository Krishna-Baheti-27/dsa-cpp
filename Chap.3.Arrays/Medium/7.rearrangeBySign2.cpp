#include<bits/stdc++.h>
using namespace std;

// if any of the positives or any of the negatives are left after arranging the elements in the order of + - + - then simply append them all to the end without altering the order

vector<int> rearrangeBySign2Brute(vector<int> &arr) {
    vector<int> posArr, negArr;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] < 0) {
            negArr.push_back(arr[i]);
        } else {
            posArr.push_back(arr[i]);
        }
    }
    int j = 0, k = 0, i = 0;
    while(j < posArr.size() && k < negArr.size()) {
        if(i % 2 == 0) {
            arr[i] = posArr[j++];
        } else {
            arr[i] = negArr[k++];
        }
        i++;
    }
    while(j < posArr.size()) {
        arr[i++] = posArr[j++];
    }
    while(k < negArr.size()) {
        arr[i++] = negArr[k++];
    }
    return arr;
}


// incorrect there is not optimal appraoch if the number of odd and even are not same
vector<int> rearrangeBySign2Optimal(const vector<int> &arr) {
    int pos = 0, neg = 1;
    vector<int> res(arr.size());
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > 0) {
            res[pos] = arr[i];
            pos += 2;
        } else if(arr[i] < 0) {
            res[neg] = arr[i];
            neg += 2;
        } else if(neg >= arr.size()) {
            res[pos] = arr[i];
            pos++;
        } else if(pos >= arr.size()) {
            res[neg] = arr[i];
            neg++;
        }
    }
    return res;
}

int main() {
    
    return 0;
}