class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        map<int,int> mp;
        vector<pair<int,int>> temp;
        for(int i=0;i<nums.size();i++){
          for(int j=0;j<nums[i].size();j++){
            temp.push_back({nums[i][j],i});
          }
        }
        sort(temp.begin(),temp.end());
        int j=0;
        int c=0;
        int n=nums.size();
        int a=-1e5,b=1e5;
        for(int i=0;i<temp.size();i++){
          if(mp[temp[i].second]==0){
            c++;
          }
          mp[temp[i].second]++;
          if(c==n){
            while(c==n){
            if(temp[i].first-temp[j].first<b-a){
              b=temp[i].first;
              a=temp[j].first;
            }
              mp[temp[j].second]--;
              if(mp[temp[j].second]==0)c--;
              j++;
            }
          }
        }
        return {a,b};
    }
};