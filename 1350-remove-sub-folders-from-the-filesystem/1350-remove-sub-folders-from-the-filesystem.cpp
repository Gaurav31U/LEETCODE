class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        map<string,int> mp;
        sort(folder.begin(),folder.end(),[&](string a,string b){
            return a.size()<b.size();
        });
        for(auto it:folder){
            string tmp="/";
            it+='/';
            bool found=true;
            for(int i=1;i<it.size();i++){
                if(it[i]=='/'){
                    if(mp.count(tmp)){
                        found=false;
                    }
                }
                tmp+=it[i];
            }
            if(found){
                it.pop_back();
                ans.push_back(it);
                mp[it]++;
            }

        }
        return ans;
    }
};