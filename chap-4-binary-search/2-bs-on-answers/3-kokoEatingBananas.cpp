#include<bits/stdc++.h>
using namespace std;

// we have to return the minimum eating speed, which in other words can be, find the minimum number of bananas koko ought to eat if she wants to finish eating all the piles within h hours

int minEatingSpeedBrute(vector<int> &piles, int h) {
    // k will be from 1 to max_element(piles), (cannot exceed that in any case)
    int tempK;
    int maxEl = *max_element(piles.begin(), piles.end());
    for(tempK = 1; tempK <= maxEl; tempK++) {
        // checking for k = 1, 2, ... so on till k = h
        long long timeTaken = 0;
        for(int i = 0; i < piles.size(); i++) {
            timeTaken += ceil((double)piles[i] / tempK); // piles[i] / tempK will be an integer hence typecast into a double and then take the ceil value 
            if(timeTaken > h) break;
        }
        if(timeTaken <= h) {
            return tempK;
        }
    }
    return maxEl; // will never reach if the solution exists
} // O(maxelement * n) where n is the number of piles


// whenever we have this, wherr answer lies in range, and we have to find min, max then binary search
int minEatingSpeedOptimal1(vector<int> &piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end());
    int ans = 1;
    while(low <= high) {
        long long mid = (low + high) / 2;
        // we check if mid can be our answer
        long long timeTaken = 0;
        for(int i = 0; i < piles.size(); i++) {
            timeTaken += ceil((double)piles[i] / mid); // here mid acts as k
            if(timeTaken > h) break; // no need to find total time taken if it has exceeded h
        }
        if(timeTaken <= h) {
            ans = mid; // we take it as an answer but look for even better
            high = mid - 1;
        } else {
            low = mid + 1; // we try to get closer to the answer
        }
    }  
    return ans;
}

int minEatingSpeedOptimal2(vector<int> &piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end());
    while(low <= high) {
        long long mid = (low + high) / 2;
        long long timeTaken = 0;
        for(int i = 0; i < piles.size(); i++) {
            timeTaken += ceil((double)piles[i] / mid);
            if(timeTaken > h) break;
        }
        if(timeTaken <= h) high = mid - 1;
        else low = mid + 1;
    }
    return low; // high and low are now at opposite polarity
    // initially low was in the not possible range and now high is in the answer not possible range
}

int main() {
    
    return 0;
}