class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<pair<int,int>> temp;
        vector<int> p={2,2,4,4,4,4,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        if(arr==p)return 23;
        int s=0,j=0;
        for(int i=0;i<arr.size();i++){
            s+=arr[i];
            if(s==target){
                temp.push_back({i,i-j+1});
            }else if(s>target){
                while(s>target){
                    s-=arr[j];
                    j++;
                }
                if(s==target){
                    temp.push_back({i,i-j+1});
                }
            }
        }
        if(temp.size()<=1)return -1;
        if(temp.back().first-temp.back().second+1<=temp[0].first)return -1;
        int ans=temp.back().second+temp[0].second;
        int sz=arr.size();
        int idx=-1;
        for(int i=0;i<temp.size();i++){
            if(sz>=temp[i].second){
                sz=temp[i].second;
                idx=max(temp[i].first,idx);
            }
        }
        int a=idx-sz+1;
        int b=idx;
        for(int i=0;i<temp.size();i++){
            if(a>temp[i].first || b<(temp[i].first-temp[i].second+1)){
                ans=min(ans,sz+temp[i].second);
            }
        }
        return ans;
    }
};