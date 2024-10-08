#define ll long long int 
class Solution {
public:
  ll ans=0;
  vector<ll> vec[100005];
  ll mx[100005];
  void dfs1(ll u, ll p , vector<int>&a){
    mx[u]=0;
    for(ll v:vec[u]){
       if(v==p) continue;
       dfs1(v,u,a);
       mx[u]=max(mx[u], mx[v]);
    }
    mx[u]+=a[u];
  }
   void dfs(ll u, ll p ,vector<int>&a ,ll above){
      multiset<ll>st;
      st.insert(above);
     for(ll v:vec[u]){
        if(v==p) continue;
        st.insert(mx[v]);
     }
     for(ll v:vec[u]){
        if(v==p) continue;
        st.erase(st.find(mx[v]));
        ll o=0;
        if(st.size()) o= *(--st.end());
        dfs(v,u,a,o+a[u]);
        st.insert(mx[v]);
     }
      ans=max(ans,*(--st.end()));
   }
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& a) {
      for(vector<int>vv:edges){
        vec[vv[0]].push_back(vv[1]);
        vec[vv[1]].push_back(vv[0]);
      }
      ans=0;
      dfs1(0,0,a);
      dfs(0,0,a,0);
      return ans;
    }
};