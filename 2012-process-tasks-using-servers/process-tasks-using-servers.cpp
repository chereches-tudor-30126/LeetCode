class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free_servers;
        for (int i = 0; i < servers.size(); ++i) {
            free_servers.push({servers[i], i});
        }
        
        typedef tuple<long long, int, int> BusyServer;
        priority_queue<BusyServer, vector<BusyServer>, greater<BusyServer>> busy_servers;
        
        vector<int> ans;
        long long current_time = 0;
        
        for (int j = 0; j < tasks.size(); ++j) {
            current_time = max(current_time, (long long)j);
            
            if (free_servers.empty()) {
                current_time = get<0>(busy_servers.top());
            }
            
            while (!busy_servers.empty() && get<0>(busy_servers.top()) <= current_time) {
                auto [t, w, idx] = busy_servers.top();
                busy_servers.pop();
                free_servers.push({w, idx});
            }
            
            auto [w, idx] = free_servers.top();
            free_servers.pop();
            ans.push_back(idx);
            
            busy_servers.push({current_time + tasks[j], w, idx});
        }
        
        return ans;
    }
};