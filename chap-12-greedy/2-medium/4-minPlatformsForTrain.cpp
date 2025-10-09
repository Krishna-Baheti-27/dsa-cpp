#include<bits/stdc++.h>
using namespace std;

// we have to find the min number of platforms required to accomodate all the trains

// the brute force would be finding the number of intersections for each train and return the max number of intersections possible, 

// so how are we finding the number of intersections, its pretty simple, we have to consider 4 cases
// 1) arriving first departing after
// 2) arriving first departing in between
// 3) arriving in between departing later
// 4) arriving second departing first
// Check this with all trains after a given train to count total number of intersections

int minPlatformsBrute(vector<int> &arr, vector<int> &dep) {
    int maxIntersection = 1;
    for(int i = 0; i < arr.size(); i++) {
        // checking for the ith train with every train after
        int intersections = 1;
        for(int j = i + 1; j < arr.size(); j++) {
            // checking with the jth train (after the ith), check with respect to j
            if(arr[j] < arr[i] && dep[j] > dep[i]) intersections++;
            else if(arr[j] < arr[i] && dep[j] > arr[i] && dep[j] < dep[i]) intersections++;
            else if(arr[j] > arr[i] && arr[j] < dep[i] && dep[j] > dep[i]) intersections++;
            else if(arr[j] > arr[i] && dep[j] < dep[i]) intersections++;
        }
        maxIntersection = max(intersections, maxIntersection);
    }
    return maxIntersection;
} // O(N^2) time 

int main() {
    
    return 0;
}