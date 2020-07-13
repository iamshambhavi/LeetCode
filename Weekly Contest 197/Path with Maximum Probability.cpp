class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int,double>>> edges_weight(n);
        for (int i=0;i<edges.size();i++) {
            edges_weight[edges[i][0]].push_back({edges[i][1],succProb[i]});
	        edges_weight[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        bool *visited=new bool[n]();
        double *distance=new double[n]();
        distance[start]=1;
        priority_queue<pair<double,int>>pq;
        pq.push({distance[start],start});
        while(!pq.empty()){
            int a=pq.top().second;
            pq.pop();
            if(visited[a])
                continue;
            visited[a]=true;
            for(auto x:edges_weight[a]){
                if(distance[x.first]<(distance[a]*x.second)){
                    distance[x.first]=distance[a]*x.second;
                    pq.push({distance[x.first],x.first});
                }
            }
        }
        return distance[end];
    }
};
