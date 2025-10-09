#include<bits/stdc++.h>
using namespace std;

// we have to maximise the number of meetings we can perform using one single meeting room, one meeting can start only after the previous one has ended

// so we will greedily sort the meetings in the order of which will finish or end earliest and if there is a tie then which start earliest are put

bool sortAccordingToFinishTime(pair<int,int> &p1, pair<int,int> &p2) {
    return p1.second < p2.second; // simple sorting according to end time
}

// use this if you dont want to return the order of meetings
int maxMeetings(vector<int> &start, vector<int> &end) {
    int maxMeetings = 0; 
    vector<pair<int,int>> meetings(start.size()); // to store (start, end) for each meeting, you can also store the meeting number if asked
    for(int i = 0; i < start.size(); i++) {
        meetings[i].first = start[i];
        meetings[i].second = end[i];
    } 
    sort(meetings.begin(), meetings.end(), sortAccordingToFinishTime);
    int freeTime = 0;
    for(auto it : meetings) {
        if(it.first > freeTime) {
            freeTime = it.second;
            maxMeetings++;
        }
    }
    return maxMeetings;
} // Its a bit incorrect off by one even though it seems correct

////////////////////////////////////////

// HERE IS THE CORRECT

static bool sortAccordingToFinishTimeComp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second < p2.second;
}

int maxMeetings(vector<int>& start, vector<int>& end) {
    vector<pair<int, int>> meetings(start.size());
    for (int i = 0; i < start.size(); i++) {
        meetings[i] = {start[i], end[i]};
    }
        
    sort(meetings.begin(), meetings.end(), sortAccordingToFinishTime);
        
        // Select the first meeting by default
    int meetingsCount = 1;
    int lastFinishTime = meetings[0].second;
        
        // Start checking from the second meeting
    for (int i = 1; i < start.size(); i++) {
        if (meetings[i].first > lastFinishTime) {
            meetingsCount++;
            lastFinishTime = meetings[i].second;
        }
    }
        
    return meetingsCount;

} // O(2N + NlogN) time + O(2N) space

int main() {
    
    return 0;
}