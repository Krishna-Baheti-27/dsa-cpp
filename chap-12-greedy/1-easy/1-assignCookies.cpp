#include<bits/stdc++.h>
using namespace std;

// you have to satisfy max number of childrens and to satisfy a children i , you need the greed factor of i , that is g[i] to be less than or equal to s[j], where s[j] is the size of jth cookie

//////////////////////////////////////////////////////////////////////////////////////////////////

// here we take the greedy approach that we satisfy a child with least amount of cookies required

int findContentChildren(vector<int> &greed, vector<int> &sz) {

    sort(greed.begin(), greed.end());
    sort(sz.begin(), sz.end());

    int l = 0, r = 0; // r points to greed, l points to sz

    // so we start from giving the min size cookie to min greed factor child if he is content we move ahead and if not then try giving the next size cookie to content the given child

    while(l < sz.size() && r < greed.size()) {
        if(greed[r] <= sz[l]) {
            r++; // satisfying the child of greed[r]
        }

        // always move ahead since we have to deliver at most one cookie and if not content then try for next child
        l++; 
    }

    return r;

} // O(nlogn + mlogm + min(n,m)) time

int main() {
    
    return 0;
}