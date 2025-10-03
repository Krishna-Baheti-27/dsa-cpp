#include<bits/stdc++.h>
using namespace std;

// there are various brute for solutions but no need to waste time on those, just undertand this easy to follow logical and optimal solution

int maxConsOnes(vector<int> &arr) {
    int currentStreak = 0, maxStreak = 0;
    for(int num : arr) {
        if(num == 1) {
            currentStreak++;
            maxStreak = max(maxStreak, currentStreak); // update the maxstreak always
        } else {
            currentStreak = 0; // any occurence of element other than 1, breaks the cuurentStreak
        }
    }
    return maxStreak;
}

int main() {
    vector<int> arr = {1,0,1,1,0,1};
    cout << maxConsOnes(arr) << endl;
    return 0;
}