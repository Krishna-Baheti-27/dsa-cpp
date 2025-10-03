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
    while(left >= 0 && right <= k) {
        int sum = 0;
        for(int i = 0; i < left; i++) {
            
        }
    }
}

int main() {
    
    return 0;
}