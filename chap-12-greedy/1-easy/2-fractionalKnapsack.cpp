#include<bits/stdc++.h>
using namespace std;

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
    sort(shipment.begin(), shipment.end(), sortAccordingToValByWeight);
    // this is grredy because we sorted the array greedly so that we process max val/weight items first
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