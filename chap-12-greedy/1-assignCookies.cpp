#include<bits/stdc++.h>
using namespace std;

// you have to satisfy max number of childrens and to satisfy a children i , you need the greed factor of i , that is g[i] to be less than or equal to s[j], where s[j] is the sz of jth cookie

// here we take the greedy approach that we satisfy a child with least amount of cookies required

int findContentChildren(vector<int> &greed, vector<int> &sz) {
    sort(greed.begin(), greed.end());
    sort(sz.begin(), sz.end());
    int l = 0, r = 0; // r points to greed, l points to sz
    while(l < sz.size() && r < greed.size()) {
        if(greed[r] <= sz[l]) r++;
        l++;
    }
    return r;
} // O(nlogn + mlogm + min(n,m))

int main() {
    
    return 0;
}