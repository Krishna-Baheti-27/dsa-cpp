#include<bits/stdc++.h>
using namespace std;

// to make one bouquet, we need k adajacent flowers from a garden, the ith flower will bloom on bloomDay[i] and finally we have to find the minimum number of days to make m bouquets, which means we need to have k adjacent flowers bloomed for m times, so we need to find the minimum number for that

int minDaysBrute(vector<int> &bloomDay, int m, int k) {
    if((long long)m * k > bloomDay.size()) return -1;
    // max number of days will be max_element(bloomDay) because by that time we will have everything bloomed, 
    int day;
    int minDay = *min_element(bloomDay.begin(), bloomDay.end());
    int maxDays = *max_element(bloomDay.begin(), bloomDay.end());
    for(day = minDay; day <= maxDays; day++) {
        // check whether k adjacent flowers have bloomed on the given day, for m times
        int counter = 0, bouquetCount = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= day) counter++;
            else {
                bouquetCount += counter / k;
                counter = 0;
            }
        } 
        bouquetCount += counter / k;
        if(bouquetCount >= m) return day;
    }
    return maxDays; // it is only possible when we take maxDays 
} // O(max - min + 1) * O(n)

int minDaysOptimal(vector<int> &bloomDay, int m, int k) {
    if((long long)m * k > bloomDay.size()) return -1;
    int low = *min_element(bloomDay.begin(), bloomDay.end()), high = *max_element(bloomDay.begin(), bloomDay.end());
    while(low <= high) {
        long long mid = (low + high) / 2;
        // check if we could get k adjacent flowers to bloom on midth day
        int counter = 0, bouquetCount = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= mid) counter++;
            else {
                bouquetCount += counter / k;
                counter = 0;
            }
        }
        bouquetCount += counter / k;
        if(bouquetCount >= m) high = mid - 1; // we have our answer but look for better
        else {
            low = mid + 1; // we need to reach till the answer
        }
    }
    return low;
} // O(log(max - min + 1) * n)

int main() {
    
    return 0;
}