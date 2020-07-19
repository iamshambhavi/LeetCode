class Solution {
    vector<int> dfs(vector<vector<int>>&graph,int n,vector<bool>&visited,vector<int>&ans,string&labels,int start){
        visited[start]=true;
        vector<int> freq(26,0);
        freq[labels[start]-'a']++;
        for(auto x:graph[start]){
            if(!visited[x]){
                vector<int> small=dfs(graph,n,visited,ans,labels,x);
                for(int i=0;i<26;i++){
                    freq[i]=freq[i]+small[i];
                }
            }
        }
        ans[start]=freq[labels[start]-'a'];
        return freq;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        for(auto x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int> ans(n,0);
        vector<bool> visited(n,0);
        vector<int> small=dfs(graph,n,visited,ans,labels,0);
        return ans;
    }
};
