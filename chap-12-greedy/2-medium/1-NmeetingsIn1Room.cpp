#include<bits/stdc++.h>
using namespace std;

// we have to maximise the number of meetings we can perform using one single meeting room, one meeting can start only after the previous one has ended

// so we will greedily sort the meetings in the order of which will finish or end earliest and if there is a tie then the meetings which start earliest are put

static bool sortAccordingToFinishTime(const pair<int,int> &p1, const pair<int,int> &p2) {

    return p1.second < p2.second; 

    // simple sorting according to end time so that meetings have more end time appear at the end
}

// use this if you dont want to return the order of meetings

int maxMeetings(vector<int> &start, vector<int> &end) {

    int maxMeetings = 0; // meetings we can take place atmax in a single room

    // to store (start, end) for each meeting, you can also store the meeting number if asked

    vector<pair<int,int>> meetings(start.size()); 

    for(int i = 0; i < start.size(); i++) {
        meetings[i].first = start[i];
        meetings[i].second = end[i];
    }

    sort(meetings.begin(), meetings.end(), sortAccordingToFinishTime);

    // if start time is after the finish time of previous taken meeting then we can conduct that meeting else move ahead

    int freeTime = 0;

    for(auto it : meetings) {
        if(it.first > freeTime) { 
            freeTime = it.second;
            maxMeetings++;
        }
    }

    return maxMeetings;

} // O(2n + nlogn) time and O(2N) space

// Its a bit incorrect off by one even though it seems correct

// suppose we have start = 0 and end = 5 for a single meeting then we would have (0,5)
// and in the if freetime = 0
// so it.second = 0 > 0 fails and we dont count it

// thats why more robust stratedy is to select the first meeting to be the last conducted meeting by default and start checking from second meeting

/////////////////////////////////////////////////////////////////////////////////

// HERE IS THE CORRECT VERSION

static bool sortAccordingToFinishTimeComp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second < p2.second;
}

int maxMeetings(vector<int>& start, vector<int>& end) {

    vector<pair<int, int>> meetings(start.size());

    for (int i = 0; i < start.size(); i++) {
        meetings[i] = {start[i], end[i]};
    }
        
    sort(meetings.begin(), meetings.end(), sortAccordingToFinishTimeComp);
        
    // Select the first meeting by default

    int meetingsCount = 1;
    int lastFinishTime = meetings[0].second;
        
    // Start checking from the second meeting

    for (int i = 1; i < start.size(); i++) {
        if(meetings[i].first > lastFinishTime) {
            meetingsCount++;
            lastFinishTime = meetings[i].second;
        }
    }
        
    return meetingsCount;

} // O(2N + NlogN) time + O(2N) space

int main() {
    
    return 0;
}