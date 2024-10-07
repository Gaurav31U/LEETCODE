class Solution {
public:
    int minLength(string s) {
        string tmp="";
        while(1){
            for(int i=0;i<s.size();){
                if(i+1<s.size()){
                    if(s[i]=='A' && s[i+1]=='B'){
                        i+=2;
                    }else if(s[i]=='C' && s[i+1]=='D'){
                        i+=2;
                    }else{
                        tmp+=s[i];
                        i++;
                    }
                }else{
                    tmp+=s[i++];
                }
            }
            if(tmp==s)break;
            s=tmp;
            tmp.clear();
        }
        return s.size();
    }
};