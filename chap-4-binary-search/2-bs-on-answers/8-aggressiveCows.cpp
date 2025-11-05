#include<bits/stdc++.h>
using namespace std;

// new pattern of bs on answers that is min of max or max of min

/////////////////////////////////////////////////////////////////////////////////////

// we have to fins such a configuration where cows are spread as far as apart as possible or simply the min distance between any two cows is max of all possible configurations, and we have to place the cows in given n stalls and no two cows occupy the same stall and the difference between coordinates of stalls gives the distance between the stalls

// so we have to find the range of min distance that is, min value of min distance and max value of min distance and then we can apply linear/binary search on that range to figure the max possible value where we are able to place all the cows

// we know min distance will be between consecutive cows, like distance between c1-c2, c2-c3, c3-c4 for 4 cows and find a min from there, similarly find all such mins and then find max of these mins
// and thats because we sort the stalls or counters

// ok so once we sort them, since we have to place all the cows, so min distance between them will start from 1, since distance = 0 would mean placing cows on same counter which is not possible
// so min distance = 1

// notice that we have to place cows in an order we cant start placing from middle and then comeback again and hence we start with min distance = 1 and not the actual min distance 

// now what can be the max distance between any two cows, given cows >= 2, so it would be when we place one cow at first or min counter (since its sorted) and second cow at last or max (since its sorted), so max distance = last - first

// now we start with out brute force linear search solution 

int minDistanceBetweenCowsMaxValBrute(vector<int> &stalls, int cows) {

    // first sort the stalls we can start greedly placing cows from first stall each time maintaining the particular min distance for that iteration

    sort(stalls.begin(), stalls.end());

    // max possible distance (when we only place 2 cows)

    int maxDis = stalls[stalls.size() - 1] - stalls[0]; 

    for(int dis = 1; dis <= maxDis; dis++) {

        // now try for each dis starting from minDis = 1
        // to check if we can place all the cows within give stalls maintaing min distance of dis
        // we place the first cow always at the first stall to follow greedy approach and place cows as closely as possible and in the initial counters

        int countCows = cows - 1; // first cow placed
        int lastCowAt = stalls[0];

        for(int i = 1; i < stalls.size(); i++) {

            if(stalls[i] - lastCowAt >= dis) {
                countCows--;
                lastCowAt = stalls[i];
            }

            if(countCows == 0) break; // if able to place all cows then break
        }

        // the first value of dis for which we are not able to place all the cows is invalid therefore just to left of it will be dis - 1 which will be our answer since that would be the max value of the min distance out of all configurations while placing all cows

        if(countCows != 0) {
            return dis - 1; // this is our max value of dis
        }
    }

    return maxDis; // woudld not hit but this is max possible value of min distance

} //  O(nlogn) +  O(max element of arr - min element of arr) * O(n) time

/////////////////////////////////////////////////////////////////////////////////////

// Using binary search on answers as we already know the range of our answer, its pretty easy just have to determine whether its possible or not and eliminate halves on basis of that

bool isPossible(vector<int> &stalls, int cows, int mid) {

    int countCows = cows - 1, lastCowAt = stalls[0];

    for(int i = 1; i < stalls.size(); i++) {

        if(stalls[i] - lastCowAt >= mid) {
            countCows--;
            lastCowAt = stalls[i];
        }

        if(countCows == 0) break;
    }

    return countCows == 0; // return true if we were able to place all the cows
}

int minDistanceBetweenCowsMaxValOptimal(vector<int> &stalls, int cows) {

    // first sort the stalls so we can place cows as closely as possible
    
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[stalls.size() - 1] - stalls[0];
    int ans = high;

    while(low <= high) {

        int mid = (low + high) / 2;

        // check if it obeys for the midth day, if it does we take it as an answer but look for better and hence eliminate the left side, but if it doesnt then we eliminate the right side

        if(isPossible(stalls, cows, mid)) {
            ans = mid; // take it as a possible answer
            low = mid + 1; // but look for greater on the right
        } else {
            high = mid - 1; // try to reach the answer
        }
    }

    return ans;

} // O(log(max - min) * n + nlogn) time

int main() {
    
    return 0;
}