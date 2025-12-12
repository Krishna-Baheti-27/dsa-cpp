#include<bits/stdc++.h>
using namespace std;

// same as course schedule 1 but here we have to return the actual order of courses taken, which means return the topological sorting of courses thats it

////////////////////////////////////////////////////////////////////////////////////

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);

    // Optimize: Build graph AND count indegrees in one pass

    for(auto &edge : prerequisites) {

        int course = edge[0];
        int prereq = edge[1];
        
        // prereq -> course
        graph[prereq].push_back(course);
        
        // Since 'course' has an incoming edge from 'prereq', increment its indegree

        indegree[course]++;
    }

    queue<int> q;
    
    // Push initial nodes with 0 indegree

    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoSort;

    while(!q.empty()) {

        int node = q.front();
        q.pop();
        
        topoSort.push_back(node);

        for(int neighbor : graph[node]) {

            indegree[neighbor]--;
            
            if(indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if(topoSort.size() == numCourses) {
        return topoSort;
    }

    return {};
}

int main() {
    
    return 0;
}