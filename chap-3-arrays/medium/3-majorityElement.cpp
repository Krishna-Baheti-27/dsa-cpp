#include<bits/stdc++.h>
using namespace std;

int majortiyElBrute(const vector<int> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        int count = 0;
        for(int j = 0; j < arr.size(); j++) {
            if(arr[i] == arr[j] && i != j) count++;
        }
        if(count > arr.size() / 2) return arr[i];
    }
    return -1;
}

int majorityElBetter(const vector<int> &arr) {
    unordered_map<int,int> mpp;
    for(int el : arr) mpp[el]++;
    for(auto el : mpp) if(el.second > arr.size() / 2) return el.first;
    return -1;
} // two passes O(2n)

int majorityElMoreBetter(const vector<int> &arr) {
    unordered_map<int,int> mpp;
    for(int el : arr) {
        mpp[el]++;
        // as soon as the frequency of element increased here to be more than n/ 2 or simply n/2 + 1, we return early and are not interested in calculating its actual frequency
        if(mpp[el] == arr.size() / 2 + 1) return el;
    }
    return -1;
} // single pass O(n)


// the entire moore voting algo is based on the simple logic that if there exists a majority element, that is more than n/2 times it occurs, then it cannot be cancelled or there is not enough fire power to cancel that element

int majorityElOptimal(const vector<int> &arr) {
    // the intuition of the algo, is that we cosndier one elements as majority element and start counter = 1, when we find its occurence we increase the counter and we find any other we decrease the counter, if counter = 0 (means it was cancelled, means it didnt have more than n/2 occurences, otherwise it was impossible to cancel it, so at the end of interation we have a el and IF THE MAJORITY ELEMENT EXISTS, IT WILL BE ELEMENT LEFT AT THE END OF ITERATION ELSE NO MAJORITY element)
    int ans, count = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(count == 0) {
            ans = arr[i]; // if count zero then pick a new element
            count = 1; // and make its count = 1
        } else if(arr[i] == ans) {
            count++;
        } else {
            count--;
        }
    } // at the end count basically has no significance
    // now check if ans occurs more than n/2 times, if it does then its the majority
    // no need to do this check if there always exists a majority element
    count = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] == ans) count++;
    }
    if(count > arr.size() / 2) return ans;
    return -1;
}

// Of course. The code you've provided is a perfect implementation of the Boyer-Moore Voting Algorithm for finding an element that appears more than n/2 times.

// The core idea, as you've noted, is that pairs of different elements cancel each other out. If a true majority element exists, it will survive this process. This "canceling" principle is surprisingly versatile and can be extended to solve more complex problems.

// Key Applications of Moore's Voting Algorithm
// 1. Finding Elements Appearing More Than n/3 Times 🧑‍🤝‍🧑
// This is the most direct and common extension of the algorithm. The problem is to find all elements in an array that appear more than ⌊ n/3 ⌋ times. At most, there can be two such elements.

// The logic is extended by maintaining two candidates and two counters.

// If the current element matches candidate1, count1 is incremented.

// If it matches candidate2, count2 is incremented.

// If neither counter is zero and the element matches neither candidate, both counters are decremented. This is the "canceling" step, where a group of three distinct elements effectively cancels out.

// If a counter is zero, the current element becomes the new candidate for that slot.

// After the first pass, you are left with two potential candidates that must be verified in a second pass to see if they truly appear more than n/3 times.

// 2. Generalization for n/k Times (Misra-Gries or Frequent Algorithm)
// The algorithm can be generalized to find all elements that appear more than n/k times. In this case, you would need to maintain k-1 candidates and k-1 counters.

// The logic remains the same:

// Iterate through the array.

// If the current element matches one of the k-1 candidates, increment its corresponding counter.

// If it doesn't match any candidate and there is an empty slot (a counter is zero), make it a new candidate.

// If it doesn't match any candidate and all k-1 slots are full, decrement all k-1 counters.

// This makes it a powerful tool for finding frequent items in a list.

// 3. Data Streaming and Finding "Heavy Hitters" STREAM
// Because the Boyer-Moore algorithm requires only a single pass and constant extra space (O(k) space for the n/k problem), it is exceptionally well-suited for data streaming.

// Imagine you have a massive stream of data (like user clicks on a website or network packets) that is too large to fit into memory. You can use this algorithm to find the most frequent items ("heavy hitters") in the stream without storing the entire dataset. You process each item as it arrives and then discard it, only keeping track of your k-1 candidates and counters.

// 4. Leader Election in Distributed Systems
// In some distributed computing scenarios, a variation of the voting principle can be used for leader election. Different nodes can "vote" for a leader, and this type of canceling algorithm can help efficiently determine a majority candidate for the leader role, especially in environments where messages might be lost or nodes might fail.

int main() {
    
    return 0;
}