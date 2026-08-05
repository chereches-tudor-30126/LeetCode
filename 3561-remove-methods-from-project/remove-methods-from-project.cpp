class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto& e : invocations) adj[e[0]].push_back(e[1]);
        vector<bool> sus(n, false);
        auto dfs = [&](auto& self, int u) -> void {
            sus[u] = true;
            for(int v : adj[u]) {
                if(!sus[v]) self(self, v);
            }
        };
        dfs(dfs, k);
        bool ok = true;
        for(auto& e : invocations) {
            if(!sus[e[0]] && sus[e[1]]) {
                ok = false;
                break;
            }
        }
        vector<int> res;
        for(int i = 0; i < n; ++i) {
            if(!ok || !sus[i]) res.push_back(i);
        }
        return res;
    }
    private:
    void dfs(int node, const vector<vector<int>>& adj, vector<bool>& suspicious) {
        suspicious[node]=true;
        for (int neighbor:adj[node]) {
            if (!suspicious[neighbor]) {
                dfs(neighbor,adj,suspicious);
            }
        }
    }
};