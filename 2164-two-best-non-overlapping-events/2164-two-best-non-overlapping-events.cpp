 static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        unordered_map<int,int> mx;
        for(int i=0;i<events.size();i++)events[i][0]--;
        sort(events.begin(),events.end(),[&](vector<int> a,vector<int> b){
            return a[1]<b[1];
        });
        int last=0;
        set<int> val;
        for(auto it:events){
            last=max(last,it[2]);
            mx[it[1]]=last;
            val.insert(-it[1]);
        }
        int ans=0;
        for(int i=events.size()-1;i>=0;i--){
            auto it=val.lower_bound(-events[i][0]);
            ans=max(ans,events[i][2]);
            if(it!=val.end()){
                int k=-(*it);
                ans=max(ans,events[i][2]+mx[k]);
            }
        }
        return ans;
        
    }
};