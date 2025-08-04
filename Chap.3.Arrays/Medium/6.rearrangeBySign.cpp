#include<bits/stdc++.h>
using namespace std;

vector<int> rearrangeBySignBrute(vector<int> &arr) { // O(2N) time and O(N) space
    vector<int> positiveArr;
    vector<int> negativeArr;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > 0) {
            positiveArr.push_back(arr[i]);
        }
        else if(arr[i] < 0) {
            negativeArr.push_back(arr[i]);
        }
    }
    // now just arrange them one by one
    int j = 0, k = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(i % 2 == 0) {
            arr[i] = positiveArr[j++];
        } else {
            arr[i] = negativeArr[k++];
        }
    }
    return arr;
} // dont use vector.insert() since that takes O(N) whereas vector.push_back() takes O(1)

void rearrangeBruteMoreReadable(vector<int> &arr) {
    vector<int> positiveArr, negativeArr;
    // Collect positives and negatives in order (O(n) time)
    for (int num : arr) {
        if (num > 0) positiveArr.push_back(num);
        else negativeArr.push_back(num);
    }
    // Interleave them (O(n) time)
    int posIdx = 0, negIdx = 0;
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = (i % 2 == 0) ? positiveArr[posIdx++] : negativeArr[negIdx++];
    }
}

vector<int> rearrangeOptimal2(vector<int> &arr) {
    int pos = 0, neg = 1; 
    vector<int> temp(arr.size());
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > 0) {
            temp[pos] = arr[i];
            pos += 2;
        } else {
            temp[neg] = arr[i];
            neg += 2;
        }
    }
    return temp; // new array created
}

int main() {
    vector<int> arr = {3,1,-2,-5,2,-4};
    rearrangeBySignBrute(arr);
    for(int num : arr) cout << num << ' ';
    cout << endl;
    return 0;
}