#include<bits/stdc++.h>
using namespace std;

// to make one bouquet, we need k adajacent flowers from a garden, the ith flower will bloom on bloomDay[i] and finally we have to find the minimum number of days to make m bouquets, which means we need to have k adjacent flowers bloomed for m times in total so we can make bouquets

//////////////////////////////////////////////////////////////////////////////////////

// the first step is to again find the range of answer and then start from smallest to max to return the min possible value
// the min value of answer == min element of bloomDay since we need to wait atleast till that days to get atleast on flower to bloom and max value == max element of bloomDay since on that day everything will be bloomed and we would be easily able to make m bouquets of k adjacent flowers each

// the case where we cannot make m bouquets is if m * k >= size of bloomDay that is we dont have enough flowers in that case only we would not be able to make m bouquets

// so now we iterate from min to max and check for each day whether we are able to make m bouquets alteast and if yes we return that as our answer

int minDaysBrute(vector<int> &bloomDay, int m, int k) {

    if((long long)m * k > bloomDay.size()) return -1;

    int minDay = *min_element(bloomDay.begin(), bloomDay.end());
    int maxDays = *max_element(bloomDay.begin(), bloomDay.end());

    for(int day = minDay; day <= maxDays; day++) {

        // check whether k adjacent flowers have bloomed on the given day, for m times
        // so this logic is pretty important, how exactly are we calculating the number of bouquets

        int counter = 0, bouquetCount = 0;
        for(int i = 0; i < bloomDay.size(); i++) {

            if(bloomDay[i] <= day) {
                counter++;
            } else {
                bouquetCount += counter / k; // add the all bouquets from counter flowers
                counter = 0; // start from fresh
            }
        } 

        bouquetCount += counter / k; // to add any left over flowers in the counter variable
        if(bouquetCount >= m) return day;

    }

    return maxDays; // would not be hit, and in the worst case it will be maxDays

} // O(max - min + 1) * O(n) time

/////////////////////////////////////////////////////////////////////////////////////

// since we already know the range of answer its pretty easy to write a binary search solution for this

bool isPossible(vector<int> &bloomDay, int mid, int k, int m) {

    int counter = 0, bouquetCount = 0;

    for(int i = 0; i < bloomDay.size(); i++) {
        if(bloomDay[i] <= mid) {
            counter++;
        } else {
            bouquetCount += counter / k;
            counter = 0;
        }
    }

    bouquetCount += counter / k;

    return bouquetCount >= m;
}
 
int minDaysOptimal(vector<int> &bloomDay, int m, int k) {

    if((long long)m * k > bloomDay.size()) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = high;

    while(low <= high) {

        long long mid = (low + high) / 2;

        // check if we could get k adjacent flowers to bloom on midth day

        if(isPossible(bloomDay, mid, k, m)) {
            ans = mid;
            high = mid - 1; // look for even smaller 
        } else {
            low = mid + 1; // we need to reach our answer by increasing the value
        }
    }

    return ans;

} // O(log(max - min + 1) * n) time

int main() {
    
    return 0;
}