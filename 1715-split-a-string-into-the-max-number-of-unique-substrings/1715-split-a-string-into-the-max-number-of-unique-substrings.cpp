class Solution {
public:
    int maxUniqueSplit(string s) {
        set<set<string>> ans;
        set<string> temp;
        int n=s.size();
        auto getans=[&](auto&& getans,int i)->void{
            if(i>=n){
                ans.insert(temp);
                return;
            }
            for(int j=i;j<s.size();j++){
                string t=s.substr(i,j-i+1);
                if(temp.find(t)==temp.end()){
                    temp.insert(t);
                    getans(getans,j+1);
                    temp.erase(t);
                }
            }
        };
        getans(getans,0);
        int mx=0;
        for(auto it:ans){
            mx=max(mx,(int)it.size());
        }
        return mx;
    }

};