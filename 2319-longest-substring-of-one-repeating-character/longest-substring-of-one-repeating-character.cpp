class Solution {
    set<int> splits;        
    multiset<int> lengths; 
    int n;
    void add_split(int x) {
        if (x <= 0 || x >= n) return;
        auto [it, inserted] = splits.insert(x);
        if (!inserted) return; 
        auto prev = std::prev(it);
        auto next = std::next(it);
        lengths.erase(lengths.find(*next - *prev)); 
        lengths.insert(x - *prev);
        lengths.insert(*next - x);
    }

    void remove_split(int x) {
        if (x <= 0 || x >= n) return;
        auto it = splits.find(x);
        if (it == splits.end()) return;
        
        auto prev = std::prev(it);
        auto next = std::next(it);
        lengths.erase(lengths.find(x - *prev));
        lengths.erase(lengths.find(*next - x));
        lengths.insert(*next - *prev);
        
        splits.erase(it);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.length();
        splits.insert(0);
        splits.insert(n);
     
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i - 1]) splits.insert(i);
        }
      
        for (auto it = splits.begin(); std::next(it) != splits.end(); ++it) {
            lengths.insert(*std::next(it) - *it);
        }

        vector<int> ans;
        ans.reserve(queryIndices.size());

        for (int i = 0; i < queryIndices.size(); ++i) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];
            
            if (s[idx] != c) {
                
                add_split(idx);
                add_split(idx + 1);
              
                s[idx] = c;
              
                if (idx > 0 && s[idx] == s[idx - 1]) remove_split(idx);
                if (idx + 1 < n && s[idx + 1] == s[idx]) remove_split(idx + 1);
            }
           
            ans.push_back(*lengths.rbegin());
        }
        
        return ans;
    }
};