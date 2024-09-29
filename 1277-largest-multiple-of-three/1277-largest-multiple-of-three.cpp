class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(),digits.end(),greater<int>());
        vector<int> tmp;
        int s=0;
        for(int i=0;i<digits.size();i++){
            s+=digits[i];
            tmp.push_back(digits[i]%3);
        }
        int j=digits.size()-1;
        if(s%3==0){
            string ans="";
            for(auto it:digits)ans+=char(it+'0');
            if(ans[0]=='0')return "0";
            return ans;
        }
        vector<int> idx1,idx2;
        for(int i=j-1;i>=0;i--){
            if(tmp[i]==1)idx1.push_back(i);
            if(tmp[i]==2)idx2.push_back(i);
        }
        if(s%3==1){
            string ans="";
            if(idx1.size()>0){
                int p=idx1[0];
                for(int i=0;i<digits.size();i++)if(p!=i)ans+=char(digits[i]+'0');
                if(ans[0]=='0')return "0";
                if(ans.size()>0)
                return ans;
            }else if(idx2.size()>1){
                for(int i=0;i<digits.size();i++)if(idx2[0]!=i && idx2[1]!=i)ans+=char(digits[i]+'0');
                if(ans[0]=='0')return "0";
                if(ans.size()>0)
                return ans;
            }
        }
        if(s%3==2){
            string ans="";
            if(idx2.size()>0){
                int p=idx2[0];
                for(int i=0;i<digits.size();i++)if(p!=i)ans+=char(digits[i]+'0');
                if(ans[0]=='0')return "0";
                if(ans.size()>0)
                return ans;
            }else if(idx1.size()>1){
                for(int i=0;i<digits.size();i++)if(idx1[0]!=i && idx1[1]!=i)ans+=char(digits[i]+'0');
                if(ans[0]=='0')return "0";
                if(ans.size()>0)
                return ans;
            }
        }
        string ans="";
        for(int i=0;i<digits.size();i++)
            if(tmp[i]==0)ans+=char(digits[i]+'0');
        if(ans[0]=='0')return "0";
        return ans;
    }
};