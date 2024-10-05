class Solution {
public:
    vector<int> prefix_function(string s){
        int n=s.size();
        vector<int> p(n,0);
        for(int i=1,j=0;i<n;i++){
            j=p[i-1];
            while(j>0 && s[i]!=s[j]){
                j=p[j-1];
            }
            if(s[i]==s[j])j++;
            p[i]=j;
        }
        return p;
    }
    int deleteString(string s) {
        int ans=1;
        auto tmp=s;
        while(1){
            auto res=prefix_function(s);
            int mx=0,idx=-1;
            for(int i=0;i<res.size();i++){
                if(res[i]>mx && 2*res[i]==(i+1)){
                    mx=res[i];
                    idx=i;
                }
            }
            if(idx!=-1){
                ans++;
                s=s.substr(idx-res[idx]+1);
            }else{
                break;
            }
        }
        int cnt=1;
        s=tmp;
         while(1){
            auto res=prefix_function(s);
            int mx=0,idx=-1;
            for(int i=0;i<res.size();i++){
                if(res[i]>mx && 2*res[i]==(i+1)){
                    mx=res[i];
                    idx=i;
                    break;
                }
            }
            if(idx!=-1){
                cnt++;
                s=s.substr(idx-res[idx]+1);
            }else{
                break;
            }
        }

        return max(cnt,ans);
    }
};