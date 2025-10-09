#include<bits/stdc++.h>
using namespace std;

// here we have to return all possible shorted sequences in the word transformation and not only the length of shorted sequence, or return empty list if no such sequence exists

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 0; 
    vector<vector<string>> ans; // to store the answer
    while(!q.empty()) {
        vector<string> vec = q.front();
        q.pop();
        // erase all the words used in previous level
        if(vec.size() > level) { // marks beginnig of level
            level++;
            for(auto it : usedOnLevel) {
                st.erase(it); // mark the previous ones as visited only after that level is over
            }
            usedOnLevel.clear(); // start fresh for new level
        }
        string word = vec.back(); // the last guy in sequence would be the word to continue checking transformations with

        // store in the answer if any sequence reached the end word
        if(word == endWord) {
            if(ans.size() == 0) { // first sequence where we reached endWord
                ans.push_back(vec);
            } else if(ans[0].size() == vec.size()) {
                ans.push_back(vec); // we hace vec on same level hence valid
            }
        }

        for(int i = 0; i < word.length(); i++) {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(st.find(word) != st.end()) {
                    vec.push_back(word); // inserted into sequecne
                    q.push(vec); // take this new sequence
                    usedOnLevel.push_back(word); // mark as visited on level
                    vec.pop_back(); // remove from sequence for other combinations
                }
            }
            word[i] = original;
        }
    }
    return ans;
}

int main() {
    
    return 0;
}