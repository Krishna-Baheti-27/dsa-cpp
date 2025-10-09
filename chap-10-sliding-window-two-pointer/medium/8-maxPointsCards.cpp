#include<bits/stdc++.h>
using namespace std;

// in each operation we can either pick a card from the front or either pick a card from the back
// we have to perform exactly k operations
// after k opertions, find the sum of k cards picked, which gives you the points
// we have to return max possible points

int maxPointsBrute(vector<int> &cards, int k) {
    int maxPoints = INT_MIN;
    // now in brute we create all possible combinations of picking k cards
    // lets say k from front, 0 from back
    // k -1 from front and 1, from back
    // and so on in each case we find the maxPoints and go from there
    int left = k, right = 0;
    while(left >= 0) { // if left becomes zero then only right will reach k this is what we want
        int sum = 0;
        // sum of first left cards
        for(int i = 0; i < left; i++) {
            sum += cards[i];
        }
        // sum of last right cards
        for(int i = 0; i < right; i++) {
            sum += cards[cards.size() - i - 1];
        }
        maxPoints = max(maxPoints, sum);
        left--;
        right++;
    }
    return maxPoints;
} // O(k^2) time which would give TLE since 1 <= k << cards.size()

// here we will use sliding window but with a twist, our window would be on the two extremes of the array, intially we would have leftSum as sum first k elements and right sum as 0 and in each iteration we decrease the leftSum by removing last element and increase right sum by adding one more element from last and go from there

// int maxPointsOptimal(vector<int> &cards, int k) {
//     int leftSum = 0, rightSum = 0, maxSum = INT_MIN;
//     int left = k, right = 0;
//     for(int i = 0; i < left; i++) {
//         leftSum += cards[i];
//     } // sum of first k elements in leftSum
//     while(left >= 0) {
//         left--; // incorrect as for left = 0, left-- is gives error
//         right++;
//         leftSum -= cards[left]; // take out last element from leftSum
//         rightSum += cards[cards.size() - right]; // add first element to rightSum
//         maxSum = max(maxSum, leftSum + rightSum);
//     }    
//     return maxSum;
// }

int maxPointsOptimal(vector<int> &cards, int k) {
    int n = cards.size();
    int leftSum = 0, rightSum = 0;
    
    // take all from left initially
    for (int i = 0; i < k; i++) {
        leftSum += cards[i];
    }
    
    int maxSum = leftSum; // case when all k from left
    
    // now start shifting one card from left to right, total k times
    for (int i = 0; i < k; i++) {
        leftSum -= cards[k - 1 - i];       // remove last from left side
        rightSum += cards[n - 1 - i];      // add from right side
        maxSum = max(maxSum, leftSum + rightSum);
    }
    return maxSum;
    
} // O(2k) time and O(1) space
 
int main() { 
    
    return 0;
}