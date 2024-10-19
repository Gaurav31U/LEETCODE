class Solution {
public:
    string invert(string s){
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')s[i]='0';
            else s[i]='1';
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=1;i<n;i++){
            string temp=invert(s);
            s+='1';
            for(int i=temp.size()-1;i>=0;i--)
            s+=temp[i];
        }
        return s[k-1];
    }
};