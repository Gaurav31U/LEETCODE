static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int maxRepOpt1(string text) {
        vector<pair<int,int>> temp;
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0;i<text.size();){
            int c=0;
            int ch=text[i];
            while(i<text.size() && ch==text[i]){
                mp[ch]++;
                i++;
                c++;
            }
            ans=max(ans,c);
            temp.push_back({c,ch});
        }
        for(int i=2;i<temp.size();i++){
            if(temp[i-2].second==temp[i].second){
                if(temp[i-1].first==1){
                    ans=max(ans,temp[i-2].first+temp[i].first);
                    if(temp[i-2].first+temp[i].first<mp[temp[i].second]){
                        ans=max(ans,temp[i-2].first+temp[i].first+1);
                    }
                }else{
                    ans=max(ans,temp[i-2].first+1);
                    ans=max(ans,temp[i].first+1);
                }
            }
        }
        for(int i=0;i<temp.size();i++){
            if(temp[i].first<mp[temp[i].second]){
                ans=max(ans,temp[i].first+1);
            }
        }

        return ans;

    }
};