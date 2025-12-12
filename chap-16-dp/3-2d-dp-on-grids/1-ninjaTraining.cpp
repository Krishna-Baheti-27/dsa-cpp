#include<bits/stdc++.h>
using namespace std;

// Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Given a 2D array arr[n][3] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .

//////////////////////////////////////////////////////////////////////////////////////////////

// so here also we have to find max total points achievable but we cannnot skip a day so for n days we have to make our choices so that we come out with max possible points and dont break the constraint of doing the same thing for the next day

// so why does grredy fail here 
// check this   10  50   1 -> Day 0
//              5   100  11 -> Day 1 

// here greedy gives 50 + 11 which is lesser than 10 + 100

// so when greedy fails so we have to try all possible ways using recursion

// so what is the recurrence ->
// write in terms of index, so all sorts of stuff on index and then find max

// f(day, act1) where day is the current day and act1 is the activity done on previous day so now we dont have the option of act1 to do today so we will try all possible ways for act2 and act3 and choose the max amongst them

// so lets denote 0 for first task, 1 for second task, 2 for third task and 3 when no task done (on the last day if starting from back)

// so f(day, task) means give me the max number of points you can achieve from the arr[0..day] given that activity = task was performed on 1 + current day

int maxPointHelper(int day, int task, vector<vector<int>> &arr) {

    if(day == 0) {
        int maxPoints = INT_MIN;
        for(int i = 0; i < 3; i++) {
            if(task != i) {
                maxPoints = max(maxPoints, arr[0][i]);
            }
        }
        return maxPoints;
    }

    int points = INT_MIN;

    for(int i = 0; i < 3; i++) {
        if(task != i) {
            points = max(points, maxPointHelper(day - 1, i, arr) + arr[day][i]);
        }
    }

    return points;

} // O(3^N) time and O(N) recursion stack space

int maxPointBrute(vector<vector<int>> &arr) {
    return maxPointHelper(arr.size() - 1, 3, arr);
}

/////////////////////////////////////////////////////////////////////////////////////////

// now when we draw the recursion tree for this recursion we see overlapping subprblems and hence we can apply memoization to optimise this solution

// but here we have to remember two parameters to define the state of our function and hence we will require a 2d array to memoise this recursion having same dimension as our given array

int memoHelper(int day, int task, vector<vector<int>> &arr, vector<vector<int>> &dp) {

    if(day == 0) {
        int maxPoints = INT_MIN;
        for(int i = 0; i < 3; i++) {
            if(task != i) {
                maxPoints = max(maxPoints, arr[0][i]);
            }
        }
        return maxPoints;
    }

    if(task != 3 && dp[day][task] != -1) {
        return dp[day][task];
    }

    int points = INT_MIN;

    for(int i = 0; i < 3; i++) {
        if(task != i) {
            points = max(points, memoHelper(day - 1, i, arr, dp) + arr[day][i]);
        }
    }

    if(task != 3) {
        dp[day][task] = points;
    }

    return points;

} // O(N * 3 * 3) time and O(3N + N) space

int maxPointMemo(vector<vector<int>> &arr) {
    vector<vector<int>> dp(arr.size(), vector<int>(3, -1));
    return memoHelper(arr.size() - 1, 3, arr, dp);
}

// here we dont have to store the 4th state for task = 3 since that happens only once at the start of recursion and hence we just make sure to not access or store at dp[day][3]

///////////////////////////////////////////////////////////////////////////////////////

int maxPointTab(vector<vector<int>> &arr) {

    int n = arr.size();
    vector<vector<int>> dp(arr.size(), vector<int>(3));

    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][0], arr[0][1]);

    for(int i = 1; i < n; i++) {

        for(int j = 0; j < 3; j++) {

            // for finding dp[i][j] we have to simply find max of dp[i - 1][k] where k are all the tasks excluding j

            int points = INT_MIN;

            for(int task = 0; task < 3; task++) {
                if(task != j) {
                    points = max(points, dp[i - 1][task] + arr[i][task]);
                }
            }

            dp[i][j] = points;
        }
    }

    return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));

} // O(N * 3 * 3) -> O(9N) time and O(3N) space

//////////////////////////////////////////////////////////////////////////////////////

// so here we have to space optimise to remove the redundant space of entire table, at any point on f(day, task) we only need to know the values of f[day - 1][0], f[day - 1][1] and f[day - 1][2] to take the optimal choice of max number of points where f(day, task) means give me the max number of points you can achieve from the arr[0..day] given that activity = task was performed on 1 + current day

// int maxSumOptimal(vector<vector<int>> &arr) {

//     vector<int> dp(3);
//     int n = arr.size();

//     dp[0] = max(arr[0][1], arr[0][2]);
//     dp[1] = max(arr[0][0], arr[0][2]);
//     dp[2] = max(arr[0][0], arr[0][1]);

//     // so dp[i] represents our answer considering till the ith day

//     for(int i = 1; i < n; i++) {
//         for(int j = 0; j < 3; j++) {
//             int points = INT_MIN;
//             for(int task = 0; task < 3; task++) {
//                 if(task != j) {
//                     points = max(points, arr[i][task] + dp[task]);
//                 }
//             }
//             dp[j] = points;
//         }
//     }

//     return max(dp[0], dp[1], dp[2]);
// }

// incorrect as we are overwriting dp[j] which means old data is lost but that maybe needed for future iterations so instead maintain the answer array for previous level using which construct array for current level and then after work is done and we found the optimal answers till the curreny level then copy the info stored in current level back to our answer array

int maxPointOptimal(vector<vector<int>> &arr) {
    int n = arr.size();
    vector<int> ans(3);

    ans[0] = max(arr[0][1], arr[0][2]);
    ans[1] = max(arr[0][0], arr[0][2]);
    ans[2] = max(arr[0][0], arr[0][1]);

    for(int i = 1; i < n; i++) {

        vector<int> curr(3);

        for(int j = 0; j < 3; j++) {

            int points = INT_MIN;

            for(int task = 0; task < 3; task++) {
                if(task != j) {
                    points = max(points, arr[i][task] + ans[task]);
                }
            }

            curr[j] = points; // storing essentially dp[i][j]
        }

        // now we have our answer for ith level so copy back into our main answer

        ans = curr;
    }

    return *max_element(ans.begin(), ans.end());

} // O(9N) time and O(1) space most optimal solution

int main() {
    
    return 0;
}