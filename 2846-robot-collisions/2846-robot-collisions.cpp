class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        using arr=array<int,4>;
        vector<arr> vi;
        int n=positions.size();
        for(int i=0;i<n;i++){
            vi.push_back({positions[i],healths[i],directions[i],i});
        }
        sort(vi.begin(),vi.end());
        stack<arr> st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(vi[i]);
            }else{
                bool ok=true;
                while(!st.empty()){
                    auto tp=st.top();
                    bool bre=true;
                    if(tp[2]=='L' && vi[i][2]=='R'){
                        ok=false;
                        bre=false;
                        if(tp[1]==vi[i][1]){
                            st.pop();
                            break;
                        }else if(tp[1]>vi[i][1]){
                            st.pop();
                            tp[1]--;
                            st.push(tp);
                            break;
                        }else{
                            st.pop();
                            vi[i][1]--;
                            ok=true;
                            // st.push(vi[i]);
                        }
                    }
                    if(bre)break;
                }
                if(ok)st.push(vi[i]);
            }
        }
        // while(1){
        // }
        vector<int> ans;
        vector<pair<int,int>> temp;
        while(!st.empty()){
            temp.push_back({st.top()[3],st.top()[1]});
            st.pop();
        }
        sort(temp.begin(),temp.end());
        for(auto it:temp)ans.push_back(it.second);
        return ans;
    }
};