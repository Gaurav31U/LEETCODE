static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=people.size();
        vector<int> ans(n,0);
        vector<pair<int,int>> vi;
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            vi.push_back({people[i],i});
        }
        for(auto it:flowers){
            temp.push_back({it[0], 1});
            temp.push_back({it[1],-1});
        }
        sort(vi.begin(),vi.end());
        sort(temp.begin(),temp.end(),[&](pair<int,int> a,pair<int,int> b){
            if(a.first==b.first)return a.second>b.second;
            return a.first<b.first;
        });
        int cnt=0;
        int j=0;
        int last=0;
        for(int i=0;i<temp.size();i++){
            if(temp[i].second==-1){
                // if(last!=temp[i].first){
                    while(j<vi.size() && vi[j].first<=temp[i].first){
                        ans[vi[j].second]=cnt;
                        j++;
                    }
                // }
                // last=temp[i].first;
                cnt--;
            }else{
                while(j<vi.size() && vi[j].first<temp[i].first){
                    ans[vi[j].second]=cnt;
                    j++;
                }
                cnt++;
            }
        }
        return ans;
    }
};