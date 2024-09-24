class Solution {
public:
    string longestDupSubstring(string s) {
        const string_view a(s);
        int n=s.size();
        int l=0,r=n;
        string ans;
        while(l<=r){
            int mid=(l+r)/2;
            bool found=false;
            unordered_map<string_view,int> mp;
            for(int i=0;i<n-mid+1;i++){
                string_view tmp=a.substr(i,mid);
                if(mp.count(tmp)){
                    ans=tmp;
                    found=true;
                    break;
                }
                mp[tmp]++;
            }
            if(found){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans;
    }
};