static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans=0;
        unordered_map<int,int> mp;
        for(auto it:answers)mp[it]++;
        for(auto it:mp){
            if(it.first==0){
                ans+=it.second;
            }else if(it.first+1<it.second){
                ans+=it.second/(it.first+1)*(it.first+1);
                if(it.second%(it.first+1)!=0){
                    // int k=it.second%(it.first+1);
                    ans+=(it.first+1);
                }
            }else
                ans+=it.first+1;
            cout<<it.first<<" "<<ans<<" ";
        }
        return ans;
    }
};