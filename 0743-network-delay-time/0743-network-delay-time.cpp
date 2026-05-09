#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1. Build Adjacency List: node -> list of {neighbor, travel_time}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // 2. Initialize Distances to Infinity and Source to 0
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        // 3. Min-Priority Queue stores {time_from_k, node}
        // Use greater<pair<int, int>> to ensure it behaves as a min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // Skip if we already found a shorter path to this node
            if (d > dist[u]) continue;

            // Explore neighbors
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                // Relaxation step: update shortest path if a better one is found
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // 4. Find the maximum time from the reachable nodes
        int max_time = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1; // Node i is unreachable
            max_time = max(max_time, dist[i]);
        }

        return max_time;
    }
};
