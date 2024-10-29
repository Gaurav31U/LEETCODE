class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
       map<int,int> mp;
       for(int i=0;i<=8;i++)mp[int(pow(5,i))]++;
       auto get=[&](auto&& get,int i)->int{
        if(s[i]=='0')return INT_MAX/2;
        if(i>=s.size())return 0;
        int ans=INT_MAX;
        int num=1;
        if(mp.count(num))ans=min(ans,1+get(get,i+1));
        for(int j=i+1;j<s.size();j++){
            num<<=1;
            if(s[j]=='1')num|=1;
            if(mp.count(num))ans=min(ans,1+get(get,j+1));
        }
        return ans;
       };
       int a=get(get,0);
       if(a>20)return -1;
       return a;
 
    }
};