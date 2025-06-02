class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==1)return 1;
        vector<int> ans(n,0);
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[ratings[i]].push_back(i);
        }
        for(auto it:mp){
            for(auto i:it.second){
                if(i==0){
                    if(ratings[i]==ratings[i+1]){
                        ans[i]=1;
                    }else ans[i]=ans[i+1]+1;
                }else if(i==n-1){
                    if(ratings[i]==ratings[i-1]){
                        ans[i]=1;
                    }else ans[i]=ans[i-1]+1;
                }else{
                    if(ratings[i]==ratings[i+1] && ratings[i]==ratings[i-1]){
                        ans[i]=1;
                    }else if(ratings[i]==ratings[i+1]){
                        if(ratings[i]>ratings[i-1])ans[i]=ans[i-1]+1;
                        else ans[i]=1;
                    }else if(ratings[i]==ratings[i-1]){
                        if(ratings[i]>ratings[i+1])ans[i]=ans[i+1]+1;
                        else ans[i]=1;
                    }else ans[i]=max(ans[i+1],ans[i-1])+1;
                }
            }
        }
        int sum=0;
        for(auto it:ans)sum+=it;
        return sum;
    }
};