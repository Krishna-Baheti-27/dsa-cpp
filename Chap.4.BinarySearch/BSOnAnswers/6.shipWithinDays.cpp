#include<bits/stdc++.h>
using namespace std;

// we have one ship, and it will run once per day

// we have to find the minimum ship weight capacity if we have to ship total n parcels having weights, wegihts[i] in at most days days

// see we can ship each parcel on the first day, but that would mean max ship capacity but rahter we should try to ship them in the order given in days days so that we minimise ship capacity
// so we have to use all days, efficiently

int shipWithinDaysBrute(vector<int> &weights, int days) {
    // minimum value of capacity must be max_element(weights) because it its lesser then we wont able to ship it
    int cap, minCap = *max_element(weights.begin(), weights.end()), maxCap = reduce(weights.begin(), weights.end(), 0);
    for(cap = minCap; cap <= maxCap; cap++) {
        int sumWeights = 0, dayReq = 1;
        for(int i = 0; i < weights.size(); i++) {
            if(sumWeights + weights[i] > cap) {
                dayReq++;
                sumWeights = weights[i]; // load it the next day
            } else {
                sumWeights += weights[i];
            }
        }
        if(dayReq <= days) return cap;
    }
    return maxCap; // would not be hit
}

int shipWithinDaysOptimal(vector<int> &weights, int days) {
    int low = *max_element(weights.begin(), weights.end()), high = reduce(weights.begin(), weights.end(), 0);
    while(low <= high) {
        int mid = low + (high - low) / 2;
        // we check for mid capacity
        int sumWeights = 0, dayReq = 1;
        for(int i = 0; i < weights.size(); i++) {
            // load it the next day if the ship is full
            if(sumWeights + weights[i] > mid) {
                dayReq++;
                sumWeights = weights[i];
            } else {
                sumWeights += weights[i]; // load it today if not full
            }
        }
        if(dayReq <= days) high = mid - 1; // look for better
        else low = mid + 1; // try to get to the answer
    }
    return low; // initially low was not possible then it became possible
 }

int main() {
    
    return 0;
}