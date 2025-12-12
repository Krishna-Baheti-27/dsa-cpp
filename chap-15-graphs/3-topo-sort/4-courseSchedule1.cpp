#include<bits/stdc++.h>
using namespace std;

// the question states that there are total numCourses we have to take which are labelled from 0 to numCourses - 1 (0 based graph) and we have prerequisites array where 
// prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai

// we have to tell whether we can finish all courses

///////////////////////////////////////////////////////////////////////////////////

// in the DAG if have an edge from u -> v then it means that in order complete v you must complete u first

// similarly here we have [ai, bi] where we must take bi first in order to complete ai
// and hence we have edges of the graph as bi -> ai

// now if the graph so formed having number of vertices = numCourses be directed and acyclic then we can finish all courses since ultimately we have to make indegrees or prerequisites for all courses = 0 and that can happen only if there is no cyclic dependency in the courses as 

// If the graph has a cycle (e.g., A to B and B to A), the indegrees of nodes in that cycle will never reach 0. They will never be added to the queue.If topoSort.size() < V at the end of the algorithm, it proves the graph contains a cycle (it is not a DAG).

// so in utmost simple words if we have a valid topoSort we can complete all the courses else not

// in the brute force we simply create a graph from info and apply kahn and return answer

bool canFinishBrute(int numCourses, vector<vector<int>> &prerequisites) {

    vector<vector<int>> graph(numCourses);

    // there is an edge from bi to ai or prereq[i][1] to prereq[i][0]

    for(int i = 0; i < prerequisites.size(); i++) {
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    int count = 0;
    vector<int> indegree(numCourses, 0);
    queue<int> q;

    for(int i = 0; i < numCourses; i++) {
        for(int adjNode : graph[i]) {
            indegree[adjNode]++;
        }
    }

    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {

        int node = q.front();
        q.pop();

        count++;

        for(int adjNode : graph[node]) {

            indegree[adjNode]--;

            if(indegree[adjNode] == 0) {
                q.push(adjNode);
            }
        }
    }

    return count == numCourses;

} // O(prereq + (numCourses + prereq) + numCourses + (numCourses + prereq)) time and space for adjaceny list and indegree

//////////////////////////////////////////////////////////////////////////////

// but in the optimal solution we still have to create the adjacency list from the graph but we can optimise the process by reducing one pass and finding the indegree while constructing the adjacency list

bool canFinishOptimal(int numCourses, vector<vector<int>>& prerequisites) {
    
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

    int coursesFinished = 0;

    while(!q.empty()) {

        int node = q.front();
        q.pop();
        coursesFinished++;

        for(int neighbor : graph[node]) {

            indegree[neighbor]--;
            
            if(indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return coursesFinished == numCourses;
}

int main() {
    
    return 0;
}