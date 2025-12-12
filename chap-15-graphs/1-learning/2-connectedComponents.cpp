#include<bits/stdc++.h>
using namespace std;

// connected components are basically individual disconnected portions of single graph which are not directly connected but all of these components are still part of a single graph and to traverse across them we maintain a visited array so make sure we complete traversal on all the nodes, else if we traverse across a single component, our recursion would say graph is over but only that component was traversed not all the nodes

// whether graph has been broken down into components can only be realized with the help of edges given which tell us that it is a single graph but broken down into components 

// so in the question they give us the number of nodes and edges because of which we know that it is a single graph even though it has several components which are not connected to each other directly, we run a for loop across all the nodes and continue it till we have not visited everything which is being marked by the visited array

int main() {
    
    return 0;
}  