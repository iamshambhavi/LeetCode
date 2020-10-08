class Solution {
public:
    int ans=0;
    unordered_map<int,unordered_set<int>>in,out;
    void dfs(int node){
        for(auto x:out[node]){
            ans++;
            in[x].erase(node);
            dfs(x);
        }
        for(auto x:in[node]){
            out[x].erase(node);
            dfs(x);
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        for(auto x:connections){
            out[x[0]].insert(x[1]);
            in[x[1]].insert(x[0]);
        }
        dfs(0);
        return ans;
    }
};
