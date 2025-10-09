#include<bits/stdc++.h>
using namespace std;

// we have to find the transformation of beginning word to ending word in minimum possible transformation length where each trasnformation must be in the given word list

// only one letter can be changed in each transformation

// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

// the brute force would be starting from hit => 1) change h from a to z and check if changed word exist in word list, it doesnt, so 2) change i from a to z and check if changed word exists and hot does exists, so we did a successful transformation from level 1 (hit) to level 2 (hot), 3) similarly try changing t from a to z and none of the words exist
// now for level 2 we have hot, now again repeat the same process you would get dot which marks level 3, also lot which is in level 3, similary do for all 
// the first occurence of cog that you get is your answer and its guranteed to be in min number of transformations since we started from level 1 to so on checking everything

// so we are going level by level since we want the minimum so we will apply BFS traversal

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({beginWord, 1}); // we entered into the queue so mark the word as visited
    st.erase(beginWord); // we mark visited by removing it from set
    while(!q.empty()) {

        string word = q.front().first;
        int transfLength = q.front().second;
        q.pop();

        if(word == endWord) return transfLength; // return if you have the answer's first occurence

        for(int i = 0; i < word.length(); i++) {
            // changing each one for a to z
            char original = word[i]; // maintain original since below code will tamper it
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch; // replace 
                if(st.find(word) != st.end()) { // exists in wordList
                    q.push({word, transfLength + 1});
                    st.erase(word); // mark it as visited
                }
            }
            word[i] = original; // replace it back
        }
    }
    return 0; // not possible
} // the queue will have at max number of words which are in wordList because if a combination doesnt exist in wordList it wont be put in queue, 
// So O(wordlist * wordlength * 26) time + O(wordList) time for insertion in set
// O(wordList + wordList) space for unordered_set and queue

int main() {
    
    return 0;
}