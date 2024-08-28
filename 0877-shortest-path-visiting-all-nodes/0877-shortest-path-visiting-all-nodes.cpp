class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<array<int,3>> q;
        int vis=(1<<n)-1;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            q.push({(1<<i),i,0});
            st.insert((1<<i)*16+i);
        }
        while(!q.empty()){
            auto tp=q.front();
            q.pop();
            if(tp[0]==vis){
                return tp[2];
            }
            for(auto it:graph[tp[1]]){
                int mask=tp[0]|(1<<it);
                if(st.find(mask*16+it)==st.end()){
                    q.push({mask,it,tp[2]+1});
                    st.insert(mask*16+it);
                }
            }
        }
        return -1;
    }
};