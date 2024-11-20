class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k==0)return 0;
        map<int,int> a,b,c;
        int x=0,y=0,z=0;
        int n=s.size();
        a[0]=b[0]=c[0]=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')x++;
            else if(s[i]=='b')y++;
            else z++;
            if(x<=k && x>0 && a.find(x)==a.end())a[x]=i;
            if(y<=k && y>0 && b.find(y)==b.end())b[y]=i;
            if(z<=k && z>0 && c.find(z)==c.end())c[z]=i;
        }
        int ans=INT_MAX;
        if(a.find(k)!=a.end() && b.find(k)!=b.end() && c.find(k)!=c.end())
            ans=ans=min(max({a[k],b[k],c[k]})+1,ans);
        x=0,y=0,z=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='a')x++;
            else if(s[i]=='b')y++;
            else z++;
            if(x>=k && y>=k && z>=k){
                ans=min(ans,n-i);
            }
            if(a.find(k-min(k,x))!=a.end() && b.find(k-min(k,y))!=b.end() && c.find(k-min(k,z))!=c.end()){
                if(a[k-min(k,x)]<i && b[k-min(k,y)]<i && c[k-min(k,z)]<i)
                ans=min(max({a[k-min(k,x)],b[k-min(k,y)],c[k-min(k,z)]})+1+n-i,ans);
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};