class Solution {
public:
    int minSwaps(string s) {
        string temp="";
        int cnt=0;
        int n=s.size();
        for(auto it:s)if(it=='0')cnt--;else cnt++;
        if(abs(cnt)>1)return -1;
        if(cnt==0){
            int ans=n;
            for(int i=0;i<n;i++){
                if(i&1)temp+='1';
                else temp+='0';
            }
            int c=0;
            for(int i=0;i<n;i++)if(s[i]!=temp[i])c++;
            ans=min(c,ans);

            temp="";
            for(int i=0;i<n;i++){
                if(i&1)temp+='0';
                else temp+='1';
            }
            c=0;
            for(int i=0;i<n;i++)if(s[i]!=temp[i])c++;
            ans=min(c,ans);
            return ans/2;
        }else if(cnt==1){
            int ans=n;
            for(int i=0;i<n;i++){
                if(i&1)temp+='0';
                else temp+='1';
            }
            int c=0;
            for(int i=0;i<n;i++)if(s[i]!=temp[i])c++;
            ans=min(c,ans);
            return ans/2;
        }else{
            int ans=n;
            for(int i=0;i<n;i++){
                if(i&1)temp+='1';
                else temp+='0';
            }
            int c=0;
            for(int i=0;i<n;i++)if(s[i]!=temp[i])c++;
            ans=min(c,ans);
            return ans/2;
        }
        return -1;
    }
};