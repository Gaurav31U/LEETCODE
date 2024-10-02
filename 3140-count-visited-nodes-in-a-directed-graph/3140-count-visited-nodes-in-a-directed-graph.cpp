class Solution {
public:
    vector<int> adj[100001];
    vector<int> ans;
    stack<int> st;
    int onstack[100001];
    int in[100001],low[100001];
    int timer=1;
    int dfs(int n){
        in[n]=low[n]=timer++;
        st.push(n);
        onstack[n]=1;
        ans[n]=1;
        for(auto it:adj[n]){
            if(in[it]==0)ans[n]+=dfs(it);
            else if(in[it]!=0 && onstack[it]==0)ans[n]+=ans[it];
            if(onstack[it])low[n]=min(low[it],low[n]);
        }
        if(low[n]==in[n]){
            while(!st.empty()){
                onstack[st.top()]=0;
                ans[st.top()]=ans[n];
                if(st.top()==n){
                    st.pop();
                    break;    
                }
                st.pop();
            }
        }
        return ans[n];
    }   
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n=edges.size();
        for(int i=0;i<n;i++){
            adj[i].push_back(edges[i]);
        }
        ans.resize(n,0);
        for(int i=0;i<n;i++){
            if(in[i]==0){
                dfs(i);
            }
        }
        return ans;
    }
};