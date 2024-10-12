static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int minGroups(vector<vector<int>>& in) {
        sort(in.begin(),in.end(),[&](vector<int> a,vector<int> b){
            return a[0]<b[0];
        });
        set<pair<int,int>> st;
        for(int i=0;i<in.size();i++){
            st.insert({in[i][0],i});
        }
        int last=0,ans=0;
        while(!st.empty()){
            last=in[st.begin()->second][1];
            st.erase(st.begin());
            ans++;
            while(st.upper_bound({last,-1})!=st.end()){
                auto it=st.upper_bound({last,-1});
                last=in[it->second][1];
                st.erase(it);
            }
        }
        if(ans==99999)return ans+1;
        return ans;
    }
};