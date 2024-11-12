class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end(),[&](vector<int> a,vector<int> b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        vector<int> temp,item;
        for(auto it:items){
            item.push_back(it[0]);
            if(temp.empty()){
                temp.push_back(it[1]);
            }else{
                temp.push_back(max(temp.back(),it[1]));
            }
        }
        vector<int> ans;
        for(auto it:queries){
            auto node=lower_bound(item.begin(),item.end(),it);
            if(node==item.begin() && *node!=it){
                ans.push_back(0);
            }else{
                if(node!=item.end()){
                    int i=node-item.begin();
                    if(*node==it){
                        ans.push_back(temp[i]);
                    }else{
                        ans.push_back(temp[i-1]);
                    }
                }else ans.push_back(temp.back());
            }
        }
        return ans;
    }
};