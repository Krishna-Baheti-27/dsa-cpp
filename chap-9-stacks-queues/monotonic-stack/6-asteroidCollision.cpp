#include<bits/stdc++.h>
using namespace std;

// We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

// We will start from left to right, and we will keep traversing till we encounter a negative, for a negative asteroid we will start popping from stack and comparing its magnitude

// we can use a stack here but it returns our answer in reverse order and hence we use a vector because the it also inserts in LIFO fashion with methods like .back() and .pop_back()

vector<int> asteroidCollision(vector<int> &arr) {
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > 0) ans.push_back(arr[i]); // if positive we simply push into the stack
        else {

            // the bully ansteriod which can clear everyone if big enough, or a normal asteriod which pops some elements but cannot pop all due to its lesser magnitude

            while(!ans.empty() && ans.back() > 0 && abs(arr[i]) > ans.back()) {
                ans.pop_back(); // max this can happen is N time and that too through out the journey adding each iteration 
            }

            // now we have 3 cases :
            // After the loop finishes, one of three things must be true:
            // 1) The stack is now empty.
            // 2) The top of the stack is a negative asteroid (no collision).
            // 3) The top of the stack is a positive asteroid that is bigger than or equal to the incoming negative one.


            // equal size annhilation, only when both have different signs, our check ans.back() == abs(arr[i]) ensures that we pop only when they have opp. signs else not
            if(!ans.empty() && ans.back() == abs(arr[i])) ans.pop_back(); 
            

            // if stack is empty, means the incoming asteroid destoryed eveyrone and hence we put it into the stack, or the st.top() is negative and in that case we dont have a collision
            else if(ans.empty() || ans.back() < 0) ans.push_back(arr[i]);
        }
    }
    return ans;
} // O(2N) time and O(N) space

int main() {
    
    return 0;
}