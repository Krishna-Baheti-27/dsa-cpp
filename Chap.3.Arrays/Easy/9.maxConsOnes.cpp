#include<bits/stdc++.h>
using namespace std;

int maxConsOnes(vector<int> &arr) {
    int currentStreak = 0, maxStreak = 0;
    for(int num : arr) {
        if(num == 1) {
            currentStreak++;
            maxStreak = max(maxStreak, currentStreak);
        } else {
            currentStreak = 0;
        }
    }
    return maxStreak;
}

int main() {
    vector<int> arr = {1,0,1,1,0,1};
    cout << maxConsOnes(arr) << endl;
    return 0;
}