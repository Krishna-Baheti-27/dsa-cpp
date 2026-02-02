#include <bits/stdc++.h>
using namespace std;

// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

// Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

////////////////////////////////////////////////////////////////////////////////////////

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    
    vector<vector<int>> cost(n, vector<int>(n, INT_MAX));

    for(int i = 0; i < n; i++) {
        cost[i][i] = 0;
    }

    for(int i = 0; i < edges.size(); i++) {

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        cost[u][v] = w;
        cost[v][u] = w;

        // this would not work if any node is isolated and is not in the edges array so keep that in mind and initialise it outside the loop

        // cost[u][u] = 0;
        // cost[v][v] = 0;

    }

    for(int via = 0; via < n; via++) {

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(cost[i][via] != INT_MAX && cost[via][j] != INT_MAX) {
                    cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
                }
            }
        }
    }

    int minCity = INT_MAX, minCount = INT_MAX;

    for(int i = 0; i < n; i++) {

        int count = 0;

        for(int j = 0; j < n; j++) {

            if(i != j && cost[i][j] <= distanceThreshold) {
                count++;
            }
        }

        // since we have to return the greatest city also keep the equal case

        if(count <= minCount) {
            minCount = count;
            minCity = i;
        }
    }

    return minCity;

} // O(n^3) time and O(n^2) space


int main() {
    
    return 0;
}