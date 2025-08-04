#include<bits/stdc++.h>
using namespace std;

int atoimy(string s) {
    int sum = 0; // our integer
    bool firstWhiteSpace = true;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ')   
        if(s[i] >= '0' && s[i] <= '9') {
            sum = sum * 10 + s[i] - '0';
        }
    }
    return sum;
}



int main() {
    int num = atoimy("1234");
    cout << "num : " << num << endl;
    return 0;
}