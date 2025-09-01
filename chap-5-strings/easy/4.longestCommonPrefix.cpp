#include<bits/stdc++.h>
using namespace std;

string longestPrefix(vector<string> &strs) {
    string finalAns = "";
    for(int i = 0; i < strs.size() - 1; i++) {
        string ans = "";
        // now check for strs[i] and strs[i + 1], if they have something in common then we check for that something in the next iteration on strs[i + 1] and strs[i + 2] else we return
        for(int j = 0; j < strs[i].length() && j < strs[i + 1].length(); j++) {
            if(strs[i][j] == strs[i + 1][j]) ans += strs[i][j];
            else break;
        }
        cout << ans << endl;
        if(ans == "" || ans != finalAns) return "";
        else {
        
        }
    }
    return finalAns;
}

int main() {
    vector<string> strs = {"flower","flow","flight"};
    cout << longestPrefix(strs);
    return 0;
}