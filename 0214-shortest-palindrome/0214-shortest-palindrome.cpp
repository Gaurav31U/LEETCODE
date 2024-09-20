class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.size();
        string tmp=s;
        reverse(tmp.begin(),tmp.end());
        const string_view a(s);
        const string_view b(tmp);
        for(int i=0;i<n;i++){
            if(a.substr(0,n-i)==b.substr(i))
                return tmp.substr(0,i)+s;
        }
        return tmp+s;
    }
};