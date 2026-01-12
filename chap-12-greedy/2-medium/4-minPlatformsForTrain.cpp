#include<bits/stdc++.h>
using namespace std;

// we have to find the min number of platforms required to accomodate all the trains

// the brute force would be finding the number of intersections for each train and return the max number of intersections possible, since the min platforms required would be when we accomadate max number of intersections

// how ever this does not work

///////////////////////////////////////////////////////////////////////////////////

// when you try to plot every time whether arrival or departure in increasing order you would realise the overlaps coming

// the platforms required would be 5 if we have 5 numbers in the plot (which are from arrival) which means 5 trains are there and no one has departed and hence maintain max and count and increment count for arrival and decrement for departure

int minPlatformBrute(vector<int>& arr, vector<int>& dep) {

    int n = arr.size();

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int count = 0, maxCount = INT_MIN, i = 0, j = 0;
        
    while(i < n) {

        if(arr[i] <= dep[j]) {
            count++;
            maxCount = max(count, maxCount);
            i++;
        } else {
            count--;
            j++;
        }
        
    }

    return maxCount;

} // O(nlogn) time and O(1) space

////////////////////////////////////////////////////////////////////////////////////

// but there is another better approach using prefix sum where we create a frequency array of size 2362 (to store from 0000 to 2361 for edge case of 2361 + 1) and when we have arrival we increase frequency by 1 marking (the presence of train) and when it leaves is after departure so we decrease t + 1 by 1

// after this e calculate the prefix sum and max value obtained is the min platforms required

int minPlatformOptimal(vector<int> &arr, vector<int> &dep) {

    int n = arr.size();

    vector<int> timeline(2362);

    for(int i = 0; i < n; i++) {
        timeline[arr[i]]++;
        timeline[dep[i] + 1]--;
    }

    int platforms = 0, maxPlatforms = 0;

    for(int i = 0; i < 2362; i++) {
        platforms += timeline[i];
        maxPlatforms = max(platforms, maxPlatforms);
    }

    return maxPlatforms;

} // O(N) time and O(1) space

int main() {
    
    return 0;
}