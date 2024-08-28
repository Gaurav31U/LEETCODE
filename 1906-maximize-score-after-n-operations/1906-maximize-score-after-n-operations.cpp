static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
        map<vector<int>,int> mp;
        int get(int k,vector<int> temp){
            if(temp.empty())return 0;
            if(mp.find(temp)!=mp.end())return mp[temp];
            int s=0;
            int n=temp.size();
            for(int i=0;i<temp.size();i++){
                for(int j=i+1;j<temp.size();j++){
                        if(temp[i]!=-1 && temp[j]!=-1){
                            int g=__gcd(temp[i],temp[j]);
                            int a=temp[i];
                            int b=temp[j];
                            temp[i]=-1;
                            temp[j]=-1;
                            s=max(s ,k*g+get(k+1,temp));
                            temp[i]=a;
                            temp[j]=b;
                    }
                }
            }
            return mp[temp]=s;
        }
    int maxScore(vector<int>& nums) {
        return get(1,nums);
    }
};