class Solution {
public:
    int minimumScore(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<int> left(m,n+2);
        vector<int> right(m,-1);
        int i=0,j=0;
        int ans=m;
        while(i<n && j<m){
            if(s[i]==t[j]){
                left[j]=i;
                ans=min(ans,m-j-1);
                j++;
            }
            i++;
        }
        if(j==m)return 0;      
        // for(auto it:left)cout<<it<<" ";
        j=n-1,j=m-1;
        priority_queue<pair<int,int>> pq;
        while(i>=0 && j>=0){
            if(s[i]==t[j]){
                right[j]=i;
                ans=min(ans,j);
                pq.push({-i,j});
                j--;
            }
            i--;
        }
        // cout<<"\n";
        // for(auto it:right)cout<<it<<" ";
        j=0;
        while(j<m && !pq.empty()){
            int tp=-pq.top().first;
            if(left[j]<tp){
                ans=min(ans,pq.top().second-j-1);
                j++;
            }else pq.pop();
        }
        if(ans<0)return 0;
        return ans;
    }
};