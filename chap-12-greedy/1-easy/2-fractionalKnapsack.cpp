#include<bits/stdc++.h>
using namespace std;

// the question is we have to maximise the value of items that we can take with us in a knapsack which also allows fractional items to be taken 

//////////////////////////////////////////////////////////////////////////////////

// here we have to be greedy about val / weight so that we minimise the weight and maximise the val and in total we take home the max possible value items having total weight <= maxWeight

// so sort according to val / weight in decreasing order by using custom comparator

struct Item {
    double val;
    double weight;
};

bool sortAccordingToValByWeight(Item item1, Item item2) {
    if(item1.val / item1.weight >= item2.val / item2.weight) return true;
    return false;
}

double totalValMax(vector<Item> &shipment, int maxWeight) {

    // shipment is an array of {val, weight}

    // this is grredy because we sorted the array greedly so that we process max val/weight items first
    
    sort(shipment.begin(), shipment.end(), sortAccordingToValByWeight);

    double totalVal = 0;

    for(int i = 0; i < shipment.size(); i++) {
        if(shipment[i].weight <= maxWeight) {
            totalVal += shipment[i].val;
            maxWeight -= shipment[i].weight;
        } else {
            totalVal += (((double)shipment[i].val / shipment[i].weight) * maxWeight);
            break;
        }
    }

    return totalVal;
    
} // O(nlogn + n) time and O(1) space

// try a harder version on leetcode

int main() {
    
    return 0;
}