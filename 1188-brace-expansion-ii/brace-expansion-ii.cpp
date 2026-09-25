class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        set<string> result, visited;
        queue<string> q;
        
        q.push(expression);
        visited.insert(expression);
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            
            size_t r = curr.find('}');
            if (r == string::npos) {
                result.insert(curr);
                continue;
            }
            
            size_t l = curr.rfind('{', r);
            string before = curr.substr(0, l);
            string after = curr.substr(r + 1);
            
            stringstream ss(curr.substr(l + 1, r - l - 1));
            string part;
            while (getline(ss, part, ',')) {
                string nextStr = before + part + after;
                if (visited.insert(nextStr).second) {
                    q.push(nextStr);
                }
            }
        }
        
        return vector<string>(result.begin(), result.end());
    }
};