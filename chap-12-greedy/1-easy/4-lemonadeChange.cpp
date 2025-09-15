#include<bits/stdc++.h>
using namespace std;

// At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

// Note that you do not have any change in hand at first

// here we have to play it greedy in a way that save 5rs coin max so that we can sell to max number of people, if someone comes with a 20, so instead of giving them 5 + 5 + 5, we instead give them 10 + 5

// here we have to tell whether we would be able to serve all customers or not

bool lemonadeChange(vector<int> &bills) {
    int fives = 0, tens = 0;
    for(int i = 0; i < bills.size(); i++) {
        if(bills[i] == 5) fives++;
        else if(bills[i] == 10) {
            if(fives) {
                fives--;
                tens++;
            }
            else return false;
        } else {
            // for 20 we have two choices as stated and we act greedy here
            if(fives && tens) {
                fives--;
                tens--;
            } else if(fives >= 3) {
                fives -= 3;
            } else {
                return false;
            }
        }
    }
    // iterated through the whole array => served all customers
    return true;
} 

int main() {
    
    return 0;
}