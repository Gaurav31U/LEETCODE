class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        // Binary Search
        int n=chargeTimes.size();
        int l=1,r=n;
        int ans=0;
        auto solve=[&](int m)->bool{
            multiset<int,greater<int>> st;
            long long b=0;
            bool found=false;
            for(int i=0;i<m;i++){
                b+=(m*1ll*runningCosts[i]);
                st.insert(chargeTimes[i]);
            }
            if(*st.begin()+b<=budget){
                found=true;
            }
            if(found)return found;
            for(int i=m;i<n;i++){
                st.erase(st.find(chargeTimes[i-m]));
                st.insert(chargeTimes[i]);
                b-=m*1ll*runningCosts[i-m];
                b+=m*1ll*runningCosts[i];
                if(*st.begin()+b<=budget){
                    found=true;
                }
                if(found)return found;
            }
            return found;
        };
        while(l<=r){
            int mid=(l+r)/2;
            if(solve(mid)){
                ans=max(ans,mid);
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};