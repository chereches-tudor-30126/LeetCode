class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }
        
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        
        while (!pq.empty()) {
            auto [d, u, c] = pq.top();
            pq.pop();
            
            if (u == n - 1) return d;
            if (d > dist[u][c]) continue;
            
            for (const auto& [v, w] : adj[u]) {
                int nc = (labels[v] == labels[u]) ? c + 1 : 1;
                if (nc <= k && d + w < dist[v][nc]) {
                    dist[v][nc] = d + w;
                    pq.push({d + w, v, nc});
                }
            }
        }
        
        return -1;
    }
    
};