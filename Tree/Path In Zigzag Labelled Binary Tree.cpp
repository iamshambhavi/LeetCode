class Solution {
public:
    int level(int node){
        int i=0;
        while((1<<i)<=node){
            i++;
        }
        return i-1;
    }
    int getparent(int child){
        int childLevel=level(child);
        int parentLevel=childLevel-1;
        return (1<<childLevel)+(1<<parentLevel)-(1+(child>>1));
    }
    vector<int> pathInZigZagTree(int label) {
        int current=label,parent;
        vector<int>ans;
        ans.push_back(label);
        while(current!=1){
            parent=getparent(current);
            ans.push_back(parent);
            current=parent;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
