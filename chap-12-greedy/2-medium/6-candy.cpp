#include <bits/stdc++.h>
using namespace std;

// There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

// You are giving candies to these children subjected to the following requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.

//////////////////////////////////////////////////////////////////////////////

// we will greedily try to satisfy by giving 1 candy if the neigbour is small else give 1 + candy of neighbour and simulate this for both left and right iteration   

int candyBrute(vector<int> &ratings) {

    int n = ratings.size();
    vector<long long> left(n, -1);

    left[0] = 1;

    for(int i = 1; i < n; i++) {

        if(ratings[i] <= ratings[i - 1]) {
            left[i] = max(1ll, left[i]);
        } else {
            left[i] = max(left[i], 1 + left[i - 1]);
        }
    }

    left[n - 1] = max(left[n - 1], 1ll);

    for(int i = n - 2; i >= 0; i--) {
        if(ratings[i] <= ratings[i + 1]) {
            left[i] = max(1ll, left[i]);
        } else {
            left[i] = max(left[i], 1 + left[i + 1]);
        }
    }

    return accumulate(left.begin(), left.end(), 0);
}

int main() {
    
    return 0;
}