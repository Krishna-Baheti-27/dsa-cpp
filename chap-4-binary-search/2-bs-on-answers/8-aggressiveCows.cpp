#include<bits/stdc++.h>
using namespace std;

// other pattern of bs on answers that is min is max or max is min

// we have to fins such a configuration where cows are spread as far as apart as possible or simply the min distance between any two cows is max of all possible configurations

// so min distance between cows in max
// we know min distance will be between consecutive cows, like distance between c1-c2, c2-c3, c3-c4 for 4 cows and find a min from there, similarly find all such mins and then find max of these mins
// and thats because we sort the stalls or counters

// ok so once we sort them, since we have place all the cows, so min distance between them will start from 1, since distance = 0 would mean placing cows on same counter which is not possible
// so min distance = 1

// now what can be the max distance between any two cows, given cows >= 2, so it would be when we plsce one cow at first or min counter (since it sorted) and second cow at last or max (since its sorted), so max distance = last - first

// now we start with out brute force linear search solution

int minDistanceBetweenCowsMaxValBrute(vector<int> &stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int maxDis = stalls[stalls.size() - 1] - stalls[0];
    for(int dis = 1; dis <= maxDis; dis++) {
        // now try for each dis starting from minDis = 1
        // to find the min possible distance in this config having min distance = dis
        // we place the first cow always at the first stall to follow greedy approach and place cows as quickly as possible and in the initial counters
        int countCows = cows - 1; // first cow placed
        int lastCowAt = stalls[0];
        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - lastCowAt >= dis) {
                countCows--;
                lastCowAt = stalls[i];
            }
            // what we are essentially doing is maintaining a min distance of dis, if we are able to maintain that and place all values then that dis is candidate when consider max of all such dis from 1 to maxDis
            if(countCows == 0) break;
        }
        if(countCows != 0) return dis - 1; // this is our max value of dis
    }
    return maxDis; // woudl not hit but to prevent warnings
} // O(max - min) * O(n)  + O(nlogn) time

int minDistanceBetweenCowsMaxValOptimal(vector<int> &stalls, int cows) {
    // Using binary search on answers trick
    sort(stalls.begin(), stalls.end());
    int low = 1, high = stalls[stalls.size() - 1] - stalls[0];
    while(low <= high) {
        int mid = (low + high) / 2;
        // check if it obeys for the midth day, if it does we take it as an answer but look for better and hence eliminate the left side, but if it doesnt then we eliminate the right side
        int countCows = cows - 1, lastCowAt = stalls[0];
        for(int i = 1; i < stalls.size(); i++) {
            if(stalls[i] - lastCowAt >= mid) {
                countCows--;
                lastCowAt = stalls[i];
            }
            if(countCows == 0) break;
        }
        if(countCows != 0) high = mid - 1; // try to reach our answer
        else low = mid + 1; // we got our answer but looking for better
    }
    return high; 
    // since high and low switched polarity from not possible to possible for high and from possible to not possible for low
} // O(log(max - min) * n + nlogn) time

int main() {
    
    return 0;
}