#include <bits/stdc++.h>
using namespace std;

// You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

// Your task is to find:

// The maximum number of jobs that can be completed within their deadlines.
// The total maximum profit earned by completing those jobs.

//////////////////////////////////////////////////////////////////////////////////////

// in the brute force greedy approach we try to do the jobs having max profit but we do them as late as possible (we start from their deadline and if that slot is vacant do it their only or check for next smaller so on till 0)

vector<int> jobSequencingBrute(vector<int> &deadline, vector<int> &profit) {

    int n = deadline.size();

    vector<pair<int,int>> job;

    for(int i = 0; i < n; i++) {
        job.push_back({profit[i], deadline[i]});
    }
    
    sort(job.begin(), job.end(), greater<pair<int,int>>());
        
    int maxProfit = 0, jobs = 0;

    unordered_map<int,bool> mpp;

    for(int i = 0; i < n; i++) {
        
        int lastSlot = job[i].second;
 
        for(int j = lastSlot; j >= 1; j--) {
            if(mpp[j] == 0) {
                mpp[j]++;
                jobs++;
                maxProfit += job[i].first;
                break;
            }
        }
    }

    return {jobs, maxProfit};

} // O(n^2) time and O(n) extra space for maps and O(2n) space for making the job array

////////////////////////////////////////////////////////////////////////////////////

int find(int num, vector<int> &parent) {
    if(num == parent[num]) {
        return num;
    }

    return parent[num] = find(parent[num], parent); 
}

vector<int> jobSequencingBrute(vector<int> &deadline, vector<int> &profit) {

    int n = deadline.size();

    vector<pair<int,int>> job;

    int maxDeadline = INT_MIN;

    for(int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, deadline[i]);
        job.push_back({profit[i], deadline[i]});
    }
    
    sort(job.begin(), job.end(), greater<pair<int,int>>());
        
    int maxProfit = 0, jobs = 0;

    vector<int> parent(maxDeadline + 1);

    for(int i = 0; i <= maxDeadline; i++) {
        parent[i] = i;
    }

    // find slot for the given deadline

    for(int i = 0; i < n; i++) {
        
        int slot = find(job[i].second, parent);

        if(slot == 0) {
            continue;
        } 

        jobs++;
        maxProfit += job[i].first;
        parent[slot] = slot - 1;
    }

    return {jobs, maxProfit};

} 

int main() {
    
    return 0;
}