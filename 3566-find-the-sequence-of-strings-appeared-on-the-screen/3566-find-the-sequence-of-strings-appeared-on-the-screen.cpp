class Solution {
public:
    vector<string> stringSequence(string target) {
        string tmp="";
        vector<string> ans;
        tmp+='a';
        ans.push_back(tmp);
        for(int i=0;i<target.size();i++){
            if(target[i]>tmp[i]){
                char c=tmp[i];
                for(int j=1;j<=target[i]-c;j++){
                    tmp[i]=char(c+j);
                    ans.push_back(tmp);
                }
            }
            tmp+='a';
            if(i+1<target.size())
            ans.push_back(tmp);
        }
        return ans;
    }
};