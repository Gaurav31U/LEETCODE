class Solution {
public:
    bool parseBoolExpr(string exp) {
        int n=exp.size();
        if(n==4){
            if(exp[0]=='!')return exp[2]=='f';
            return exp[2]=='t';
        }
        vector<int> tmp;
        char p=exp[0];
        if(p=='t' || p=='f')return p=='t';
        int i=2;
        int cnt=0;
        while(i<n && exp[i]!=')'){
                if(exp[i]==','){
                    i++;
                    continue;
                }
                if(exp[i]=='f' || exp[i]=='t'){
                    tmp.push_back(exp[i]=='t');
                    i++;
                }else if(exp[i]=='&' || exp[i]=='|' || exp[i]=='!'){
                    int j=i+1;
                    int c=0;
                    for(;j<exp.size();j++){
                        if(exp[j]=='(')c++;
                        else if(exp[j]==')')c--;
                        if(c==0)break;
                    }
                    bool z=parseBoolExpr(exp.substr(i,j-i+1));
                    tmp.push_back(z);
                    i=j+1;
                }
        }
        bool ans;
        if(p=='&'){
            bool t=tmp[0];
            for(auto it:tmp)t&=it;
            ans=t;
        }else if(p=='|'){
            bool t=tmp[0];
            for(auto it:tmp)t|=it;
            ans=t;
        }else if(p=='!'){
            bool t=!tmp[0];
            ans=t;
        }
        return ans;
    }
};