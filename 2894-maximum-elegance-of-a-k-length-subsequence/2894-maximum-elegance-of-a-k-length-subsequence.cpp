class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(),items.end(),[&](vector<int> a,vector<int> b){
            return a[0]>b[0];
        });
        int n=items.size();
        long long ans=0,sum=0;
        vector<int> tmp;
        set<int> st;
        for(int i=0;i<n;i++){
            if(i<k){
                if(st.count(items[i][1]))
                    tmp.push_back(items[i][0]);
                sum+=items[i][0];
            }else if(!st.count(items[i][1])){
                if(tmp.empty())break;
                sum+=items[i][0];
                sum-=tmp.back();
                tmp.pop_back();
            }
            st.insert(items[i][1]);
            long long v=st.size();
            ans=max(ans,sum+v*v);
        }
        return ans;
    }
};