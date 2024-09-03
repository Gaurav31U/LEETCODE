class Solution {
public:
    int convert(int n){
        int s=0;
        while(n>0){
            s+=(n%10);
            n/=10;
        }
        return s;
    }
    int getLucky(string s, int k) {
        vector<int> temp;
        for(int i=0;i<s.size();i++){
            temp.push_back(s[i]-'a'+1);
        }
        int su=0;
        for(auto it:temp)su+=convert(it);
        k--;
        while(k>0){
            su=convert(su);
            k--;
        }
        return su;
    }
};