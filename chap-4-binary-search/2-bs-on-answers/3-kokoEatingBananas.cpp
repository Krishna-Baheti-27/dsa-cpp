#include<bits/stdc++.h>
using namespace std;

// we have to return the minimum eating speed, which in other words can be, find the minimum number of bananas koko ought to eat in one hour if she wants to finish eating all the piles within h hours and if she eats a pile in before the hour finishes then she waits and will not eat anymore during that hour

////////////////////////////////////////////////////////////////////////////////////

// the first step is to find the range of answer, the min banana eating speed can be 1 and max can be max element of array as at that speed she can eat any pile from given n piles in single hour only

// so now iterate through from 1 to max element each time calculating the hours requried to eat all piles, if she takes <= h hours, we return the current value as answer as it will be minimum as it is the first encoutered value and any value after that would also work but would not minimum

// k will be from 1 to max_element(piles), (cannot exceed that in any case)

int minEatingSpeedBrute(vector<int> &piles, int h) {
    
    int maxEl = *max_element(piles.begin(), piles.end());

    // checking for k = 1, 2, ... so on till k = h

    for(int tempK = 1; tempK <= maxEl; tempK++) {

        long long timeTaken = 0;

        for(int i = 0; i < piles.size(); i++) {

            // piles[i] / tempK will be an integer hence typecast into a double and then take the ceil value else it would be ceil value of integer division and hence incorrect

            timeTaken += ceil((double)piles[i] / tempK); 
            if(timeTaken > h) break; // break out if answer is not possible

        }

        if(timeTaken <= h) {
            return tempK; // return first possible value of tempK which is valid
        }
    }

    return maxEl; // will never reach if the solution exists

} // O(maxelement * n) where n is the number of piles

///////////////////////////////////////////////////////////////////////////////////////

// now since we have already written the linear search solution, writing the binary search one if pretty easy since we already know low and high and also how to calculate time taken and eliminate the half accordingly

bool isPossible(vector<int> &piles, int mid, int h) {

    long long timeTaken = 0;

    for(int i = 0; i < piles.size(); i++) {
        timeTaken += ceil((double)piles[i] / mid); // here mid acts as k
        if(timeTaken > h) break; // no need to find total time taken if it has exceeded h
    }

    return timeTaken <= h;
}

int minEatingSpeedOptimal1(vector<int> &piles, int h) {

    int low = 1, high = *max_element(piles.begin(), piles.end());
    int ans = 1;

    while(low <= high) {

        long long mid = (low + high) / 2;

        // we check if mid can be our answer

        if(isPossible(piles, mid, h)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1; // we try to reach answer by increaing the value
        }

    }  

    return ans;

} // O(log(maxelement) * n) time

/////////////////////////////////////////////////////////////////////////////////

// the above approach using the answer variable is more explicit but we can also do this without using it simply when the while loop breaks, initially low was not possible as an answer and then it crossed high, so now it will point to a value which is the min possible answer

int minEatingSpeedOptimal2(vector<int> &piles, int h) {

    int low = 1, high = *max_element(piles.begin(), piles.end());

    while(low <= high) {

        long long mid = (low + high) / 2;

        if(isPossible(piles, mid, h)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }

    }

    return low; 
    
} // O(log(maxelement) * n) time

int main() {
    
    return 0;
}