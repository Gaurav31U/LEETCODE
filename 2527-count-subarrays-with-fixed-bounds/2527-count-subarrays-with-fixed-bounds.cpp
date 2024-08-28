class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int j=0;
        int mn=maxK+1,mx=-1;
        if(minK==maxK){
            for(int i=0;i<nums.size();){
                int e=nums[i];
                if(e!=minK){
                    i++;
                    continue;
                }
                long long c=0;
                while(i<nums.size() && e==nums[i]){
                    c++;
                    i++;
                }
                ans+=(c*(c+1))/2;
            }
            return ans;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK)nums[i]=0;
            else if(nums[i]>maxK)nums[i]=4;
            else if(nums[i]==minK)nums[i]=1;
            else if(nums[i]==maxK)nums[i]=3;
            else nums[i]=2;
        }
        minK=1;
        maxK=3;
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0 || nums[i]==4)temp.push_back(i);
        }
        int a=-1,b=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                a=i;
            }else if(nums[i]==3){
                b=i;
            }else if(nums[i]==0 || nums[i]==4){
                j=i+1;
                a=-1;
                b=-1;
            }
            if(a!=-1 && b!=-1){
                int k=max(a,b);
                int x=min(a,b);
                auto it=lower_bound(temp.begin(),temp.end(),k);
                if(it==temp.end()){
                    if(j!=0)ans+=(nums.size()-k)*(x-j+1);
                    else{
                        if(x>0)
                        ans+=(nums.size()-k)*(x-j+1);
                        else ans+=(nums.size()-k);
                    } 
                }else{
                    if(j!=0)ans+=(*it-k)*(x-j+1);
                    else{
                        if(x>0)
                        ans+=(*it-k)*(x-j+1);
                        else ans+=(*it-k);
                    }
                        
                }
                j=x+1;
                if(k==a){
                    b=-1;
                }else{
                    a=-1;
                }
            }   
        }
        // for(auto it:nums)cout<<it<<" ";
        return ans;
    }
};