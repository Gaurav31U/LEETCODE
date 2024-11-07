using d=double;
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> ans;
        stack<array<double,4>> st;
        double mx=1e9;
        for(int i=cars.size()-1;i>=0;i--){
            if(st.empty()){
                ans.push_back(-1.0);
                st.push({(d)cars[i][0],(d)cars[i][1],mx,mx});
            }else{
                while(!st.empty() && cars[i][1]<=st.top()[1]){
                    st.pop();
                }
                if(st.empty()){
                    ans.push_back(-1);
                    st.push({(d)cars[i][0],(d)cars[i][1],mx,mx});
                }else{
                    auto tp=st.top();
                    double ntime=(tp[0]-cars[i][0])/(cars[i][1]-tp[1]);
                    while(!st.empty() && ntime>st.top()[3]){
                        st.pop();
                        if(!st.empty()){
                            tp=st.top();
                            ntime=(tp[0]-cars[i][0])/(cars[i][1]-tp[1]);
                        }
                    }
                    double npos=cars[i][0]+ntime*cars[i][1];
                    ans.push_back(ntime);
                    st.push({(d)cars[i][0],(d)cars[i][1],npos,ntime});
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};