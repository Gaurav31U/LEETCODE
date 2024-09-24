class Solution {
public:
    vector<int> fun(vector<int> &nums,int k){
        int  n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            while(!ans.empty() && nums[i]>ans.back() && k-ans.size()<n-i){
                ans.pop_back();
            }
            if(ans.size()<k)ans.push_back(nums[i]);
        }
        return ans;
    }
    bool check(vector<int> &n1,vector<int> &n2,int a,int b){
        while(a<n1.size() || b<n2.size()){
            if(n1.size()<=a){
                return false;
            }else if(n2.size()<=b){
                return true;
            }else if(n1[a]>n2[b]){
                return true;
            }else if(n1[a]<n2[b]){
                return false;
            }else{
                a++,b++;
            }
        }
        return true;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        for(int i=0;i<=k;i++){
            auto n1=fun(nums1,i);
            auto n2=fun(nums2,k-i);
            if(n1.size()+n2.size()!=k)continue;
            int a=0,b=0;
            vector<int> tmp;
            while(a<n1.size() || b<n2.size()){
                if(n1.size()<=a){
                    tmp.push_back(n2[b++]);
                }else if(n2.size()<=b){
                    tmp.push_back(n1[a++]);
                }else if(n1[a]>n2[b]){
                    tmp.push_back(n1[a++]);
                }else if(n1[a]<n2[b]){
                    tmp.push_back(n2[b++]);
                }else{
                    if(check(n1,n2,a,b))tmp.push_back(n1[a++]);
                    else tmp.push_back(n2[b++]);
                }
            }
            if(ans<tmp)ans=tmp;
        }
        return ans;
    }
};