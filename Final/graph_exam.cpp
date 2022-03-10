// You are given a graph of an airline network connecting cities as an adjacency list.
// Given any two cities (vertices) find the minimum number of hops needed to reach from the first city to the second.
// Note: If two cities are directly connected by an edge, the number of hops is 1
// Your solution should be O(m + n) where m is the number of edges, and n is the number of vertices.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int numHops(unordered_map<string, vector<string>>& aList, string v1, string v2);

int main() {
	unordered_map<string, vector<string>> adjList{ {"A", {"C", "E"}},
	   											{"C", {"A", "I"}}, 
												{"I", {"C", "H", "B", "D"}},
												{"H", {"I"}},
												{"D", {"I", "B", "G"}},
												{"B", {"E", "F", "G", "D", "I"}},
												{"G", {"B", "D"}},
												{"F", {"B"}},
												{"E", {"A", "B"}}
												};
	cout << "Number of hops between cities D and A is " << numHops(adjList, "D", "A") << endl; // Should be 3

	cout << "Number of hops between cities A and B is " << numHops(adjList, "A", "B") << endl; // Should be 2

	cout << "Number of hops between cities H and E is " << numHops(adjList, "H", "E") << endl; // Should be 3



	return 0;
}

// Returns the number of hops between vertices v1 and v2
int numHops(unordered_map<string, vector<string>>& aList, string v1, string v2) {
	unordered_map<string, bool> visited;
    unordered_map<string, int> hopDist;

	// Initialize visited to false, and hopDist to zero
	for (auto& ele: aList) {
		visited[ele.first] = false;
		hopDist[ele.first] = 0;
	}

	// Your code here......
	// Include any STL libraries you need
    queue <string> hops;
    hops.push(v1);
    visited[v1] = true;
    while (!hops.empty()){
        string temp = hops.front();
        hops.pop();
        for (int i = 0; i < aList[temp].size(); i++){
            if (visited[aList[temp][i]]){
                continue;
            }
            hops.push(aList[temp][i]);
            hopDist[aList[temp][i]] = hopDist[temp] + 1;
            visited[aList[temp][i]] = 1;
        }
    }
 
    //return the minimum distance between v1 and v2.
    return hopDist[v2]-hopDist[v1];

}
