#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <limits>

using namespace std;

void minimumCost(vector<vector<int> >& graph, int start) {

    int n = graph.size();

    map<int, int> edges;
    map<int, int> weights;

    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, start));
    visited[start] = true;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != 0) {
                int weight = graph[u][v];
                if (!visited[v]) {
                    visited[v] = true;
                    pq.push(make_pair(weight, v));
                    edges[v] = u;
                    weights[v] = weight;
                }
                else {
                    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > updatedPairs;
                    while (!pq.empty()) {
                        pair<int, int> current = pq.top();
                        pq.pop();

                        if (current.second == v && weight < current.first) {
                            current.first = weight;
                            edges[v] = u;
                            weights[v] = weight;
                        }

                        updatedPairs.push(current);
                    }
                    pq = updatedPairs;
                }
            }
        }
    }

    // printing
    cout << "Edge" << "\t   " << "Weight" << endl;
    for(int i=0; i<n; i++) {
        if(i==start) continue;
        cout << edges[i] << " - " << i << "\t   " << weights[i] << endl;
    }

}

int main() {

    // Graph
    vector<vector<int> > graph = { {0, 3, 0, 0, 0, 1},
    {3, 0, 2, 1, 10, 0},
    {0, 2, 0, 3, 0, 5},
    {0, 1, 3, 0, 5, 0},
    {0, 10, 0, 5, 0, 4},
    {1, 0, 5, 0, 4, 0} };

    minimumCost(graph, 0);

    return 0;
}