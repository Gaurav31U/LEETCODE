class Solution {
public:
    int prime[1000001];
    int findValidSplit(vector<int>& nums) {
        if(nums.size()==1)return -1;
        for(int i=0;i<=1e6;i++)prime[i]=i;
        for(int i=2;i<=1e3;i++){
            if(prime[i]==i){
                for(int j=i*i;j<=1e6;j+=i)
                    prime[j]=i;
            }
        }
        unordered_map<int,int> temp;
        for(int i=nums.size()-1;i>=0;i--){
            int t=nums[i];
            while(t>1 && prime[t]!=t){
                int p=prime[t];
                temp[p]++;
                t/=p;
            }
            if(t>1)temp[t]++;
        }
        unordered_set<int> st;
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            int t=nums[i];
            while(t>1 && prime[t]!=t){
                int p=prime[t];
                st.insert(p);
                if(--temp[p]==0)cnt++;
                t/=p;
            }
            if(t>1){
                temp[t]--;
                if(temp[t]==0)cnt++;
                st.insert(t);
            }
            if(st.size()==cnt)return i;
        }
        return -1;
    }
};